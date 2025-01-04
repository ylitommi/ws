#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from my_robot_interfaces.action import CountUntil
from rclpy.action import ActionServer, GoalResponse
from rclpy.action.server import ServerGoalHandle

class CountUntilServer(Node):
    def __init__(self):
        super().__init__('count_until_server')
        self.count_until_server_ = ActionServer(
            self,
            CountUntil,
            "count_until",
            goal_callback = self.goal_callback,
            execute_callback = self.execute_callback)
    
    # accepting or rejecting the goal sent by client
    def goal_callback(self, goal_request: CountUntil.Goal):
        timestring = time.strftime("%c", time.localtime())
        self.get_logger().info(f"Received goal {goal_request} at {timestring}.")
        if goal_request.target_number <= 0:
            self.get_logger().warn("Rejecting the goal, target number must be positive.")
            return GoalResponse.REJECT
        self.get_logger().info("Accepting the goal.")
        return GoalResponse.ACCEPT
    
    def execute_callback(self, goal_handle: ServerGoalHandle):
        target_number = goal_handle.request.target_number
        delay = goal_handle.request.delay
        result = CountUntil.Result()
        counter = 0
        self.get_logger().info("Executing the goal.")
        for i in range(target_number):
            counter += 1
            self.get_logger().info(str(counter))
            time.sleep(delay)
        goal_handle.succeed()
        result.reached_number = counter
        return result


        

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServer()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
