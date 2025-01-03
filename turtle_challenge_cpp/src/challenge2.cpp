#include "rclcpp/rclcpp.hpp"
//#include "example_interfaces/msg/float64.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "my_robot_interfaces/srv/stop_turtle.hpp"

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
      publisher_ = this->create_publisher<TurtleTwist>("turtle1/cmd_vel", 10);
      subscription_ = this->create_subscription<TurtlePose>("turtle1/pose", 10, std::bind(&Challenge2Node::SubscriberCallbackMethod, this, _1));
      //timer1_ = this->create_wall_timer(2s, std::bind(&Challenge2Node::TimerCallbackMethod, this));
      service_ = this->create_service<StopTurtle>("turtle1/stop_turtle", std::bind(&Challenge2Node::ServiceCallbackMethod, this, _1, _2));
      client_ = this->create_client<SetPen>("turtle1/set_pen");
      activated_ = false;
      old_x = 5.5;
    }
    
    void SubscriberCallbackMethod(const TurtlePose::SharedPtr msg) //turtlesim::msg::Pose::SharedPtr
    {
      if (activated_){
      //RCLCPP_INFO(this->get_logger(), "Message: %f, %f, %f", msg->x, msg->y, msg->theta);
        auto cmd = TurtleTwist();
        if (msg->x<=5.5){
          cmd.linear.x = 1;
          cmd.angular.z = 1;
          if (old_x >= 5.5){
            RCLCPP_INFO(this->get_logger(), "here");
            CallSetPen(0,254,0);
            old_x = msg->x;
          }
        }
        else if (msg->x>5.5){
          cmd.linear.x = 2;
          cmd.angular.z = 2;
          if (old_x < 5.5){
            CallSetPen(254,0,0);
            old_x = msg->x;
          }
        }
        publisher_->publish(cmd);
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

    void CallSetPen(uint8_t r, uint8_t g, uint8_t b) // this method is used to make client call to service
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
    rclcpp::Client<SetPen>::SharedPtr client_;
    rclcpp::Subscription<TurtlePose>::SharedPtr subscription_ ;
    rclcpp::Publisher<TurtleTwist>::SharedPtr publisher_;
    rclcpp::Service<StopTurtle>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer1_;
    //TurtlePose::SharedPtr old_pose;
    float old_x;
    bool activated_;
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
