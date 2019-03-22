#include<ros/ros.h>
#include<random_num_addition/random.h>
#include<random_num_addition/summ.h>
#include"Addition_node.h"
#include"std_msgs/Int32.h"

bool AddNode::a_instanceFlag=false;
AddNode* AddNode::a_n_Add_node=0;
ros::Subscriber ranadd_sub;

AddNode::AddNode(){
ranadd_sub=a_nh_Add.subscribe("Addition",1000, DisplayAdditionCallback);
}

AddNode* AddNode::getInstance(){
    if(!a_instanceFlag){
                a_instanceFlag = true;
                a_n_Add_node=new AddNode();
                return a_n_Add_node;
                                }
                else
                     return a_n_Add_node;
}
void AddNode::DisplayAdditionCallback(const std_msgs::Int32::ConstPtr& msg){
	std_msgs::Int32 msg_sum;
 	 msg_sum.data=msg->data;
       	ROS_INFO_STREAM(msg_sum.data <<"=sum in Display");
}

int main(int argc, char **argv)
{
ros::init(argc,argv, "Addition");
AddNode* t_Add;
t_Add=AddNode::getInstance();
ros::spin();
return 0;
}
