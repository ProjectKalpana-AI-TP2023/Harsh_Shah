#include "rclcpp/rclcpp.hpp"  
#include "geometry_msgs/msg/twist.hpp" 

//l1: library for functionality for ros2
//l2: message twist for controling motion

class ExpandingSpiralNode : public rclcpp::Node {   
//class ExpandingSpiralNode inherits from rclcpp::Node
public:
  ExpandingSpiralNode() : Node("expanding_spiral_node") {    
//initializing node
    publisher_ = create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);   
//creating publisher , Q size 10 of publisher
    timer_ = create_wall_timer(std::chrono::milliseconds(100), std::bind(&ExpandingSpiralNode::moveTurtle, this));
  }
//creating timer that will call moveTurtle ever 100 ms . std::chrono sets time duration

private:
  void moveTurtle() {
    geometry_msgs::msg::Twist msg;
// Used to set linear and angular velocities to create a spiral pattern
    msg.linear.x = linear_velocity_;
    msg.angular.z = angular_velocity_;
// Increasing linear and angular velocity to make turtle move in expanding spiral
    publisher_->publish(msg);
    linear_velocity_ += linear_increment_;
    angular_velocity_ += angular_increment_;
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
//creating pulbisher
  rclcpp::TimerBase::SharedPtr timer_;
// setting initial values and increemental values  
  double linear_velocity_ = 1.0;
  double angular_velocity_ = 0.1;
  double linear_increment_ = 0.1;
  double angular_increment_ = 0.01;
};

  int main(int argc, char** argv) {
// argc is number of cmd line arguments
// argv is  array of strings contianing cmd line arguments     
    rclcpp::init(argc, argv);
// above line initializes ros2 and it allows ros2 
// to process cmd line arguments , and configure ros2 environment
    rclcpp::spin(std::make_shared<ExpandingSpiralNode>());
//calls moveTurtle function from ExpandingSpiralNode class 
    rclcpp::shutdown();
//shutdown shuts down ros environment
    return 0;
  }


