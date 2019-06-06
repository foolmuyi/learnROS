#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "learning_communication/Person.h"


int main(int argc,char **argv)
{
    //ROS节点初始化
    ros::init(argc,argv,"talker");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
    //ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);

    //试试自定义消息类型Person
    ros::Publisher chatter_pub = n.advertise<learning_communication::Person>("chatter",1000);

    //设置循环的频率
    ros::Rate loop_rate(3);

    int count = 0;
    while (ros::ok())
    {
        //初始化std_msgs::String类型的消息
        // std_msgs::String msg;
        // std::stringstream ss;
        // ss << "hello, world" << count;
        // msg.data = ss.str();

        //初始化Person类型的消息
        learning_communication::Person msg;
        msg.name = "awsl";
        msg.gender = 1;
        msg.age = 99;

        //发布消息
        // ROS_INFO("%s", msg.data.c_str());
        ROS_INFO("Personal Information: name: %s gender: %d age: %d", msg.name.c_str(), msg.gender, msg.age);
        chatter_pub.publish(msg);

        //循环等待回调函数
        ros::spinOnce();

        //按照循环频率延时
        loop_rate.sleep();
        ++count;
    }
    return 0;
}