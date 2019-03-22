#include <ros/ros.h>
#include <random_num_addition/random.h>
#include <random_num_addition/summ.h>
#include <ros/console.h>

//#include "std_msgs/Int64.h"

class GenAddNode{
	private:
	ros::Subscriber RanGen_sub;
	ros::NodeHandle g_nh_GenAdd;
	ros::Publisher Add_pub;
	static bool g_a_instanceFlag;
	static GenAddNode* g_n_GenAdd_node; 
	public:
	static GenAddNode* getInstance();
	GenAddNode();
	static void computeAdditionCallback(const random_num_addition::random::ConstPtr& msg);
	~GenAddNode();
	};
