#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <cstdlib>

//学了service后突发奇想写的一个client，利用turtlesim功能包每秒生成一个乌龟

int main(int argc, char** argv)
{
    //初始化节点
    ros::init(argc, argv, "tooManyTurtles");

    //创建一个client
    ros::NodeHandle nh;
    ros::ServiceClient addTurtle = nh.serviceClient<turtlesim::Spawn>("spawn");

    //创建turtlesim::Spawn类型的service消息
    turtlesim::Spawn srv;
    srv.request.theta = 0;

    //设置循环频率
    ros::Rate loop_rate(1);

    while(ros::ok())
    {
        //随机获取新乌龟产生的坐标，范围为[0,11]
        srv.request.x = rand()%12;
        srv.request.y = rand()%12;

        //调用Spawn服务生成一只新乌龟
        addTurtle.call(srv);

        //延时
        loop_rate.sleep();
    }
    return 0;
}