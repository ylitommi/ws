#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/int64.hpp"
#include "my_robot_interfaces/srv/reset_counter.hpp"

using ResetCounter = my_robot_interfaces::srv::ResetCounter;
using Int64 = my_robot_interfaces::msg::Int64;
using namespace std::placeholders;
using namespace std::literals::chrono_literals;

class MyCustomNode : public rclcpp::Node {
  public:
    MyCustomNode(): Node("node_name")
    {
      publisher_ = this->create_publisher<Int64>("pub_topic_name", 10);
      subscription_ = this->create_subscription<Int64>("sub_topic_name", 10, std::bind(&MyCustomNode::SubscriberCallbackMethod, this, _1));
      timer1_ = this->create_wall_timer(2s, std::bind(&MyCustomNode::TimerCallbackMethod, this));
      service_ = this->create_service<ResetCounter>("service_name", std::bind(&MyCustomNode::ServiceCallbackMethod, this, _1, _2));
      client_ = this->create_client<ResetCounter>("reset_counter");
    }
    
    void SubscriberCallbackMethod(const Int64::sharedPtr msg)
    {
      RCLCPP_INFO(this->get_logger(), "Message: %d", msg->data);
    }

    void TimerCallbackMethod()
    {
      auto msg = Int64();
      msg.data = 10;
      publisher_->publish(msg);
    }

    void ServiceCallbackMethod(const ResetCounter::Request::SharedPtr request, const ResetCounter::Response::SharedPtr response)
    {
      RCLCPP_INFO(this->get_logger(), "Request: %d", request->reset_value);
      if (request->reset_value < 0) {
        response->success = false;
        response->message = "Cannot accept values less than 0";
      }
      else if (request->reset_value >= 0){
        response->success = true;
        response->message = "Success";
      }
    }

    void callResetCounter(int value) // this method is used to make client call to service
    {
      while (!client_->wait_for_service(1s))
      {
        RCLCPP_WARN(this->get_logger(), "Waiting for the server...");
      }
      auto request = std::make_shared<ResetCounter::Request>();
      request->reset_value = value;
      client_->async_send_request(request, std::bind(&CallClient::callbackResetCounterResponse, this, _1));
    }

    void callbackResetCounterResponse(rclcpp::Client<ResetCounter>::SharedFuture future)
    {
      auto response = future.get();
      RCLCPP_INFO(this->get_logger(), "Success flag: %d, Message: %s", (int)response->success, response->message.c_str());
    }

  private:
    rclcpp::Client<ResetCounter>::SharedPtr client_;
    rclcpp::Subscription<my_robot_interfaces::msg::Int64>::SharedPtr subscription_ ;
    rclcpp::Publisher<my_robot_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Service<ResetCounter>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer1_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MyCustomNode>();
  node->callResetCounter(20);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
