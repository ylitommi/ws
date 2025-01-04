#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from my_robot_interfaces.action import CountUntil
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.action.server import ServerGoalHandle
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup


class CountUntilServer(Node):
    def __init__(self):
        super().__init__('count_until_server')
        self.count_until_server_ = ActionServer(
            self,
            CountUntil,
            "count_until",
            goal_callback = self.goal_callback,
            cancel_callback = self.cancel_callback,
            execute_callback = self.execute_callback,
            callback_group = ReentrantCallbackGroup())
        self.get_logger().info("Action server instance has been started.")
    
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
        feedback = CountUntil.Feedback()
        counter = 0
        self.get_logger().info("Executing the goal.")
        for i in range(target_number):
            # Let's check if action is canceled (with goal_handle method .is_cancel_requested)
            if goal_handle.is_cancel_requested:
                self.get_logger().info("Canceling goal")
                goal_handle.canceled()
                result.reached_number = counter
                return result
            # do the actual execution of the goal
            counter += 1
            self.get_logger().info(str(counter))
            feedback.current_number = counter
            goal_handle.publish_feedback(feedback)
            time.sleep(delay)
        goal_handle.succeed()
        result.reached_number = counter
        return result

    def cancel_callback(self, goal_handle: ServerGoalHandle):
        self.get_logger().info("Received a cancel request from client.")
        return CancelResponse.ACCEPT

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServer()
    rclpy.spin(node, MultiThreadedExecutor())
    rclpy.shutdown()

if __name__ == "__main__":
    main()
