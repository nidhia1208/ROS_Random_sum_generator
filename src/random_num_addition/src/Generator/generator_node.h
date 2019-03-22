#include <ros/ros.h>
#include <random_num_addition/random.h>

class GeneratorNode{
private:
	ros::NodeHandle g_nh_generator;

	static bool g_nh_instanceFlag;
	static GeneratorNode* r_g_Generator_Node;

public:
	static GeneratorNode* getInstance();
	GeneratorNode();
	
	static void GenerateNumbers(int freq);
	
	~GeneratorNode(){}
};

