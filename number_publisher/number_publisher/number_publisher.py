#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import Int64
from my_robot_interfaces.srv import ResetCounter

class NumberPublisher(Node):
    def __init__(self):
        super().__init__('NumberPublisher')
        self.number_ = 0
        self.number_publisher_ = self.create_publisher(Int64, 'number',10)
        self.publish_timer1_ = self.create_timer(1.0, self.publish_number)
        self.srv_reset_counter_ = self.create_service(ResetCounter, 'reset_counter', self.callback_reset_counter)
        self.get_logger().info('Number publisher object initiated')

    def publish_number(self):
        msg = Int64()
        self.number_ += 1
        msg.data = self.number_
        self.number_publisher_.publish(msg)
        self.get_logger().info(f'NumberPublisher: {self.number_}')

    def callback_reset_counter(self, request: ResetCounter.Request, response: ResetCounter.Response):
        if request.reset_value < 0:
            response.success = False
            response.message = 'number cannot be lower than 0'
        elif request.reset_value < self.number_:
            response.success = True
            response.message = 'Success'
            self.number_ = request.reset_value
            self.get_logger().info(f'Number publisher resetted to {self.number_}')
        else:
            response.success = False
            response.message = 'Number cannot be reseted to higher than current value'
        return response


def main(args = None):
    print('starting number_publisher executable')
    rclpy.init(args = args)
    node = NumberPublisher()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
