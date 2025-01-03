#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/int64.hpp"
#include "my_robot_interfaces/srv/reset_counter.hpp"

using ResetCounter = my_robot_interfaces::srv::ResetCounter;
using namespace std::placeholders;
using namespace std::literals::chrono_literals;

class CallClient : public rclcpp::Node {
  public:
    CallClient(): Node("call_client_cpp")
    {
      client_ = this->create_client<ResetCounter>("reset_counter");
    }
    
    void callResetCounter(int value)
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
      exit(0);
    }
  private:
  rclcpp::Client<ResetCounter>::SharedPtr client_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CallClient>();
  node->callResetCounter(5);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
