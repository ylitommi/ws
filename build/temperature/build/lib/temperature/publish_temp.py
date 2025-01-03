#!/usr/bin/env python3

import requests
import time
import rclpy
from rclpy import Node
from example_interfaces.msg import Float64

class PublishTemperature(Node):
    def __init__(self):
        super().__init__('PublishTemperature_node')
        self.publisher_ = self.create_publisher(Float64, "temperature", 10)
        self.timer_ = self.create_timer(60.0, self.publish_temperature)
        
        t = time.localtime()
        current_time = time.strftime("%c", t)
        self.get_logger().info(f"Temperature publisher node initiated successfully {current_time}")

    def publish_temperature(self):
        msg = Float64()
        self.publisher_.publish(msg)



def main(args = None):
    rclpy.init(args)
    node = PublishTemperature()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
