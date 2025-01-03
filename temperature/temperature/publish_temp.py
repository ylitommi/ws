#!/usr/bin/env python3

import requests
import time
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class PublishTemperature(Node):
    def __init__(self):
        super().__init__('PublishTemperature_node')
        self.publisher_ = self.create_publisher(String, "temperature", 10)
        self.timer_ = self.create_timer(10.0, self.publish_temperature)
        
        self.t_ = time.localtime()
        current_time = time.strftime("%c", self.t_)
        
        self.get_logger().info(f"Temperature publisher node initiated successfully {current_time}")

    def publish_temperature(self):
        self.t_ = time.localtime()
        msg = String()
        msg.data = time.strftime("%c", self.t_)
        
        self.publisher_.publish(msg)
        self.get_logger().info(f"Current time sent to /temperature {msg.data}")



def main(args = None):
    rclpy.init(args=args)
    node = PublishTemperature()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
