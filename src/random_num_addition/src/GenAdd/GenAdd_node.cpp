#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include <random_num_addition/random.h>
#include <random_num_addition/summ.h>
#include "GenAdd_node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

bool GenAddNode::g_a_instanceFlag=false;
GenAddNode* GenAddNode::g_n_GenAdd_node=0;
ros::Publisher add_pub;
ros::Subscriber rangen_sub;

GenAddNode::GenAddNode(){
rangen_sub=g_nh_GenAdd.subscribe("Generator",1000, computeAdditionCallback);
add_pub=g_nh_GenAdd.advertise<std_msgs::Int32>("Addition",1000);
}

GenAddNode* GenAddNode::getInstance(){
    if(!g_a_instanceFlag){
                g_a_instanceFlag = true;
                g_n_GenAdd_node=new GenAddNode();
	ROS_INFO("GenAddNode getInstance called");
                return g_n_GenAdd_node;
                                }
                else
                        return g_n_GenAdd_node;
}

void GenAddNode::computeAdditionCallback(const random_num_addition::random::ConstPtr& msg){
std_msgs::Int32 msg_sum;
 	
	msg_sum.data=msg->x+msg->y;
	ROS_INFO_STREAM(msg->x << "=Num1");
	ROS_INFO_STREAM(msg->y << "=Num2");
	ROS_INFO_STREAM(msg_sum.data << "=Sum");
	add_pub.publish(msg_sum);
}

int main(int argc, char **argv)
{
ros::init(argc,argv, "GenAdd");
GenAddNode* t_GenAdd;
t_GenAdd=GenAddNode::getInstance();
ros::spin();
return 0;
}
