#! /usr/bin/env python3

import time
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import Int64
from my_robot_interfaces.srv import ResetCounter

class NumberCounter(Node):
    def __init__(self):
        super().__init__('reset_counter')
        self.number_counter_= self.create_subscription(Int64, 'number', self.count_number, 10)
        self.cli_reset_counter_ = self.create_client(ResetCounter, 'reset_counter')
        
        self.count_ = 0

        while not self.cli_reset_counter_.wait_for_service(1.0):
            self.get_logger().warn('Waiting for reset_counter service...')

        self.current_time_ = time.strftime("%c", time.localtime())
        self.get_logger().info(f'NumberCounter object initiated at {self.current_time_}')

    def count_number(self, number: Int64):
        self.count_ += number.data
        if number.data > 10:
            self.reset_counter(0)
        self.get_logger().info(f'Received number: {number.data}, counter value: {self.count_}')

    def reset_counter(self, value):
        request = ResetCounter.Request()
        request.reset_value = value
        future = self.cli_reset_counter_.call_async(request)
        future.add_done_callback(self.callback_reset_counter_response)
    
    def callback_reset_counter_response(self, future):
        response = future.result()
        self.get_logger().info(f'Success flag: {response.success}')
        self.get_logger().info(f'Message: {response.message}')
    
def main(args = None):
    print('starting number_counter executable')
    rclpy.init(args = args)
    node = NumberCounter()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()


if __name__ == '__main__':
    main()
