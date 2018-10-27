# include "ros/ros.h"
 #include "std_msgs/String.h"
#include "geometry_msgs/Point32.h"
#include <cstdlib>
 #include <sstream>

/*
using global variables for the x and y coordinates, so that these variables can't be changed within the main function, these stay constant unless
modified
*/

int main(int argc, char **argv){
/**
  38    * The ros::init() function needs to see argc and argv so that it can perform
  39    * any ROS arguments and name remapping that were provided at the command line.
  40    * For programmatic remappings you can use a different version of init() which takes
  41    * remappings directly, but for most command-line programs, passing argc and argv is
  42    * the easiest way to do it.  The third argument to init() is the name of the node.
  43    *
  44    * You must call one of the versions of ros::init() before using any other
  45    * part of the ROS system.
  46    */

ros::init(argc, argv, "talker");


ros::NodeHandle n;

/**
  57    * The advertise() function is how you tell ROS that you want to
  58    * publish on a given topic name. This invokes a call to the ROS
  59    * master node, which keeps a registry of who is publishing and who
  60    * is subscribing. After this advertise() call is made, the master
  61    * node will notify anyone who is trying to subscribe to this topic name,
  62    * and they will in turn negotiate a peer-to-peer connection with this
  63    * node.  advertise() returns a Publisher object which allows you to
  64    * publish messages on that topic through a call to publish().  Once
  65    * all copies of the returned Publisher object are destroyed, the topic
  66    * will be automatically unadvertised.
  67    *
  68    * The second parameter to advertise() is the size of the message queue
  69    * used for publishing messages.  If messages are published more quickly
  70    * than we can send them, the number here specifies how many messages to
  71    * buffer up before throwing some away.
  72    */


ros::Publisher chatter_pub = n.advertise<geometry_msgs::Point32>("chatter", 1000);


ros::Rate loop_rate(1);

/**
  78    * A count of how many messages we have sent. This is used to create
  79    * a unique string for each message.
  80    */

int count = 0;
while(ros::ok()){

//this is a message object, you stuff it with data and then publish it
std_msgs::String msg;

geometry_msgs::Point32 Pnt;

//generate two x and y data points from 0 to 100

Pnt.x = (std::rand() % 100 + (std::rand()/((float)RAND_MAX+1)));
Pnt.y = (std::rand() % 100 + (std::rand()/((float)RAND_MAX+1)));
Pnt.z = (Pnt.x + Pnt.y)/2.0;

std::stringstream ss;
ss << "hello world" << count;

msg.data = ss.str();


//automatically time stamped printf function
ROS_INFO("Point 1 is: [%f]",Pnt.x);
ROS_INFO("Point 2 is [%f] \n",Pnt.y);


/**
  96      * The publish() function is how you send messages. The parameter
  97      * is the message object. The type of this object must agree with the type
  98      * given as a template parameter to the advertise<>() call, as was done
  99      * in the constructor above.
 100      */

chatter_pub.publish(Pnt);

ros::spinOnce();

loop_rate.sleep();
++count;

}


return 0;



}
