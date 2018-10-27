
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point32.h"


void chatterCallback(const geometry_msgs::Point32::ConstPtr& Pnt)
   {
    //referencing the Pnt messages in memory through creating a copysss
    /*
    ROS_INFO("I heard: [%f]", Pnt->x);
    ROS_INFO("I heard 2: [%f]", Pnt->y);
    */
    ROS_INFO("Average of [%f] and [%f] is: [%f] \n",Pnt->x, Pnt->y, Pnt->z);

  }

int main(int argc, char **argv){

/**
  42    * The ros::init() function needs to see argc and argv so that it can perform
  43    * any ROS arguments and name remapping that were provided at the command line.
  44    * For programmatic remappings you can use a different version of init() which takes
  45    * remappings directly, but for most command-line programs, passing argc and argv is
  46    * the easiest way to do it.  The third argument to init() is the name of the node.
  47    *
  48    * You must call one of the versions of ros::init() before using any other
  49    * part of the ROS system.
  50    */


ros::init(argc, argv, "listener");

ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

/**
  78    * ros::spin() will enter a loop, pumping callbacks.  With this version, all
  79    * callbacks will be called from within this thread (the main one).  ros::spin()
  80    * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
  81    */

ros::spin();

return 0;


}
