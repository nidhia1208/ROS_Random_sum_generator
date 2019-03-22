#include <ros/ros.h>
#include "generator_node.h"
#include <iostream>
#include <cstdlib>
#include <random_num_addition/random.h>

using namespace std;

int freq;
bool GeneratorNode::g_nh_instanceFlag=false;
GeneratorNode* GeneratorNode::r_g_Generator_Node=0;
ros::Publisher rangen_pub;

GeneratorNode::GeneratorNode(){
        rangen_pub=g_nh_generator.advertise<random_num_addition::random>("Generator",1000);
        std::string PARAM_NAME="Frequency";
        bool ok=ros::param::get(PARAM_NAME,freq);
        if(!ok){
        ROS_FATAL_STREAM("couldnot get parameter "<<PARAM_NAME);
        exit(1);
        }
                GeneratorNode::GenerateNumbers(freq);
        }

GeneratorNode* GeneratorNode::getInstance()
{
        if(!g_nh_instanceFlag){
                g_nh_instanceFlag = true;
                r_g_Generator_Node=new GeneratorNode();
                return r_g_Generator_Node;
                                }
                else
                        return r_g_Generator_Node;
}

void GeneratorNode::GenerateNumbers(int freq){
        random_num_addition::random random_numbers;
	ROS_INFO("GenerateNumbers called");
	ros::Rate rate(10);
	while(ros::ok()){
        	int i=0;
		srand(time(0));
       		 while(i<freq){
                  	random_numbers.x=rand();
		ROS_INFO("Num1=%d",random_numbers.x);
                	random_numbers.y=rand();
		ROS_INFO("Num2=%d",random_numbers.y);
                	i++;
                	rangen_pub.publish(random_numbers);
               		     }	
       		       }
rate.sleep();
}


int main(int argc, char** argv)
	{
		ros::init(argc,argv,"generator");
		GeneratorNode* t_generator;
		t_generator=GeneratorNode::getInstance();
		ros::spin();
		return 0;
	}

