#include <ros/ros.h>
#include <service_demo/Greeting.h>

int main(int argc,char** argv){
	ros::init(argc,argv,"greetings_server");
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<service_demo::Greeting>("greetings");

	service_demo::Greeting srv;
	srv.request.name = "Neo";
	srv.request.age = 26;

	if(client.call(srv)){
	ROS_INFO("Feedback from Oracle:%s",srv.response.feedback);
	}
	else{
	ROS_INFO("Failed to call service greetings.");
	return 1;
	}
	return 0;
}