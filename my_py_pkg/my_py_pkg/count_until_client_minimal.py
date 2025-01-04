#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.action import CountUntil
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus


class CountUntilClient(Node):
    def __init__(self):
        super().__init__('count_until_client')
        self.count_until_client_ = ActionClient(
            self,
            CountUntil,
            "count_until")
        self.get_logger().info("CountUntilClient instance initiated.")
    
    def send_goal(self, target_number, delay):
        while not self.count_until_client_.wait_for_server(1.0):
            self.get_logger().warn('Waiting for Count Until service...')
        #self.count_until_client_.wait_for_server()
        goal = CountUntil.Goal()
        goal.target_number = target_number
        goal.delay = delay
        self.count_until_client_.send_goal_async(goal).add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future: ClientGoalHandle):
        self.goal_handle_ = future.result()
        if self.goal_handle_.accepted:
            self.get_logger().info("Goal got accepted.")
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)
        else:
            self.get_logger().info("Goal got rejected")
    
    def goal_result_callback(self, future):
        status = future.result().status
        result = future.result().result
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Success")
        elif status == GoalStatus.STATUS_ABORTED:
            self.get_logger().error("Aborted")
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Canceled")
        self.get_logger().info("Result: " + str(result.reached_number))

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilClient()
    node.send_goal(6,0.9)
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
