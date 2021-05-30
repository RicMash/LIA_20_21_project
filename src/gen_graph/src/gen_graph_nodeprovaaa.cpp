#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"


void odomCallback(const nav_msgs::Odometry::ConstPtr& msg){
  ROS_INFO("I heard: [%f, %f, %f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "gen_graph_node");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);

  ros::spin();

  return 0;
}