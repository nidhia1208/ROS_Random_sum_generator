#include<ros/ros.h>
#include <random_num_addition/random.h>
#include <random_num_addition/summ.h>
#include "std_msgs/Int32.h"
class AddNode{
        private:
        ros::Subscriber ranadd_sub;
        ros::NodeHandle a_nh_Add;
        static bool a_instanceFlag;
        static AddNode* a_n_Add_node;
        public:
        static AddNode* getInstance();
        AddNode();
        static void DisplayAdditionCallback(const std_msgs::Int32::ConstPtr& msg);
        ~AddNode();
	};

