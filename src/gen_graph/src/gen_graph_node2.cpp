#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include <geometry_msgs/TransformStamped.h>
#include <vector>
#include <iostream>

/* std::ofstream OutputFile("output.txt");
 */std::vector<float> old_position(2,0);
std::vector<float> current_position(2,0);
tf2_ros::Buffer* tfBuffer_ptr;

void position_Callback(const tf2_msgs::TFMessage& tf){
   /*  int transform_ok;
    transform_ok= tfBuffer.canTransform("base_link","odom",ros::Time(0));

    if(transform_ok !=0){
        geometry_msgs::TransformStamped transformStamped;
        transformStamped=tfBuffer.lookupTransform("base_link","odom",ros::Time(0));
        current_position[0]=transformStamped.transform.translation.x;
        current_position[1]=transformStamped.transform.translation.y;
        ROS_INFO("I heard [%f, %f]",current_position[0],current_position[1]);
        
    }
  ROS_INFO("fuori"); */

  /*   tf::TransformListener listener;

    tf::StampedTransform transform;
    try{
      listener.lookupTransform("odom", "base_link",  
                               ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
 */

    tf2_ros::TransformListener tfListener(*tfBuffer_ptr);

    geometry_msgs::TransformStamped transformStamped;
    try{
      transformStamped = tfBuffer_ptr->lookupTransform("odom", "base_link",
                               ros::Time::now());
      current_position[0]=transformStamped.transform.translation.x;
      current_position[1]=transformStamped.transform.translation.y;
      ROS_INFO("I heard [%f, %f]",current_position[0],current_position[1]);
      ROS_INFO("I head");

    }
    catch (tf2::TransformException &ex) {
      ROS_WARN("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

}

int main(int argc, char** argv)
{
    
    ros::init(argc, argv, "generate_graph_node");

    ros::NodeHandle n;

    ros::Subscriber sub= n.subscribe("tf",1000,position_Callback);
    tf2_ros::Buffer tfBuffer;
    *tfBuffer_ptr=tfBuffer;
    /* ros::Timer timer1=n.createTimer(ros:Duration(0.5),check1_Callback);
    ros::Timer timer2=n.createTimer(ros:Duration(0.5),check2_Callback); */
    

    ros::spin();

    return 0;       

}

