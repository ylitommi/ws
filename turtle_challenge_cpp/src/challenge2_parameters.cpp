#include "rclcpp/rclcpp.hpp"
//#include "example_interfaces/msg/float64.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "my_robot_interfaces/srv/stop_turtle.hpp"
#include <vector>

using TurtleTwist = geometry_msgs::msg::Twist;
using SetPen = turtlesim::srv::SetPen;
using TurtlePose = turtlesim::msg::Pose;
//using Float64 = example_interfaces::msg::Float64;
using StopTurtle = my_robot_interfaces::srv::StopTurtle;

using namespace std::placeholders;
using namespace std::literals::chrono_literals;

class Challenge2Node : public rclcpp::Node {
  public:
    Challenge2Node(): Node("turtle_controller")
    {
      this->declare_parameter("x_line_", 5.5); // prepares one command-line parameter (the x-coordinate of vertical line that changes color and speed of turtle)
      //this->declare_parameter("color_1", std::vector<int>())
      this->declare_parameter("color_1", std::vector<int64_t>{254,0,0});
      this->declare_parameter("color_2", std::vector<int64_t>{0,0,254});
      this->declare_parameter("velocity", 1.0);
      
      publisher_ = this->create_publisher<TurtleTwist>("turtle1/cmd_vel", 10);
      subscription_ = this->create_subscription<TurtlePose>("turtle1/pose", 10, std::bind(&Challenge2Node::SubscriberCallbackMethod, this, _1));
      //timer1_ = this->create_wall_timer(2s, std::bind(&Challenge2Node::TimerCallbackMethod, this));
      service_ = this->create_service<StopTurtle>("turtle1/stop_turtle", std::bind(&Challenge2Node::ServiceCallbackMethod, this, _1, _2));
      client_ = this->create_client<SetPen>("turtle1/set_pen");
      param_callback_handle_ = this->add_post_set_parameters_callback(std::bind(&Challenge2Node::ParamCallbackMethod, this, _1));
      
      activated_ = false;
      old_x_ = 5.5;
      x_line_ = this->get_parameter("x_line_").as_double();
      color1_ = this->get_parameter("color_1").as_integer_array();
      color2_ = this->get_parameter("color_2").as_integer_array();
      velocity_ = this->get_parameter("velocity").as_double();
    }
    
    void SubscriberCallbackMethod(const TurtlePose::SharedPtr msg) //turtlesim::msg::Pose::SharedPtr
    {
      if (activated_){
      //RCLCPP_INFO(this->get_logger(), "Message: %f, %f, %f", msg->x, msg->y, msg->theta);
        auto cmd = TurtleTwist();
        if (msg->x<=x_line_){
          cmd.linear.x = velocity_;
          cmd.angular.z = velocity_;
          if (old_x_ >= x_line_){
            RCLCPP_INFO(this->get_logger(), "here");
            CallSetPen(color1_.at(0), color1_.at(1), color1_.at(2));
            old_x_ = msg->x;
          }
        }
        else if (msg->x>x_line_){
          cmd.linear.x = 2.0*velocity_;
          cmd.angular.z = 2.0*velocity_;
          if (old_x_ < x_line_){
            CallSetPen(color2_.at(0), color2_.at(1), color2_.at(2));
            old_x_ = msg->x;
          }
        }
        publisher_->publish(cmd);
    }
  }

  //Let's handle parameter changes
  void ParamCallbackMethod(const std::vector<rclcpp::Parameter> & parameters)
  {
    for (const auto &param: parameters){
      if (param.get_name() == "x_line_"){
        x_line_ = param.as_double();
      }
    }
  }
    //
    //void TimerCallbackMethod()
    //{
    //  auto msg = Int64();
    //  msg.data = 10;
    //  publisher_->publish(msg);
    //}

    void ServiceCallbackMethod(const StopTurtle::Request::SharedPtr request, const StopTurtle::Response::SharedPtr response)
    {
      RCLCPP_INFO(this->get_logger(), "Request: %d", request->activate);
      if (request->activate) {
        response->success = "Turtle activated";
        activated_ = true;
      }
      else{
        response->success = "Turtle stopped";
        activated_ = false;
      }
    }

    void CallSetPen(int64_t r, int64_t g, int64_t b) // this method is used to make client call to service
    {
      while (!client_->wait_for_service(1s))
      {
        RCLCPP_WARN(this->get_logger(), "Waiting for the server...");
      }
      auto request = std::make_shared<SetPen::Request>();
      request->r = r;
      request->g = g;
      request->b = b;

      client_->async_send_request(request, std::bind(&Challenge2Node::CallbackResetCounterResponse, this, _1));
    }

    void CallbackResetCounterResponse(rclcpp::Client<SetPen>::SharedFuture future)
    {
      auto response = future.get();
      RCLCPP_INFO(this->get_logger(), "Pen color changed");
    }

  private:
    rclcpp::node_interfaces::PostSetParametersCallbackHandle::SharedPtr param_callback_handle_;
    rclcpp::Client<SetPen>::SharedPtr client_;
    rclcpp::Subscription<TurtlePose>::SharedPtr subscription_ ;
    rclcpp::Publisher<TurtleTwist>::SharedPtr publisher_;
    rclcpp::Service<StopTurtle>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer1_;
    //TurtlePose::SharedPtr old_pose;
    float old_x_;
    bool activated_;
    float x_line_;
    std::vector<int64_t> color1_;
    std::vector<int64_t> color2_;
    float velocity_;
    
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Challenge2Node>();
  //node->callResetCounter(20);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
