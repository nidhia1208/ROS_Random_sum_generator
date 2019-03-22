# ROS_Random_sum_generator
Application for generating sum of random numbers using ROS C++


Development approach:
Have applied Structured Approach to develop the application.

 
Application is implemented using singleton Design Pattern in C++. Each node is an instance of the class. 
There can be only a single Instance for each class.

Configurations Used:
It is built using ROS Kinetic. Frequency is configurable using rosparam. Output can be seen in the logging console output.

Logic:
Have applied Publisher Subscriber method for sending the messages between the three nodes defined:
Generator_node
GenAdd_node
Addition_node

1. Generator_node is responsible for continuously random number value pairs and publishing them in a message of type “random” on topic “Generator”
-Random msg type is a composite message of two int32 types of variables, each will be responsible for holding the two randomly generated numbers and published as a single message of type “random”.
- It configures the frequency via rosparam “Frequency” parameter set in launch file.
 or using command line $ rosparam set frequency <value>

2. GenAdd_node acts as an interface between Generator and Addition nodes. It subscribes to “random” msg on “Generator” topic , computes the sum of its variables (‘x’ and ‘y’) and Publishes as a Message of type “std_msgs::Int32” on topic “Addition” .


3. Addition node is responsible for displaying the generated sum on the logging console.
-It subscribes to the messages on topic “Addition” and displays the sum of the random variables on the console.





CMakeList.txt file consist of following elements:

find_package() is used to get the information about the package’s build time dependencies.
add_message_files() declares the message files to be built.
generate_message() generates the message header files.
catkin_package() declares the catkin package’s runtime dependencies.
add_executable() defines executable  and its source files.
target_link_libraries() defines link libraries for each executable.



Commands to launch the nodes:
source devel/setup.bash
$ roslaunch random_num_addition start_generating.launch

command to set the configurable frequency parameter:
$ rosparam set frequency <value> 










