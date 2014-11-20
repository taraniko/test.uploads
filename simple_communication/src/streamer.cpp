
#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include <cstdlib>

int main(int argc, char **argv){
 
  ros::init(argc, argv, "streamer");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int16>("/task1/numbers", 1000);
  ros::Rate loop_rate(1);

  int number;

  while (ros::ok()){

    number = rand() % 100 + 1;

    std_msgs::Int16 msg;
    msg.data = number;
    ROS_INFO("I sent: %d", msg.data);
    chatter_pub.publish(msg);
    
    ros::spinOnce();
    
    loop_rate.sleep();

  }

  return 0;
}

