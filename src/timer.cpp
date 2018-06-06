#include <Eigen/Geometry>
#include "timer.hpp"
#include <string>
#include <iostream>

namespace ttimer
{

timerNode::timerNode(ros::NodeHandle &nh)
{

    rtkSub_ = nh.subscribe("SingleBaselineRTK",10,&timerNode::singleBaselineRTKCallback,
                                                        this, ros::TransportHints().tcpNoDelay());
    timerPub_ = nh.advertise<rostime_to_gps::offsetMsg>("offsetMsg", 10);
}

void timerNode::singleBaselineRTKCallback(const gbx_ros_bridge_msgs::SingleBaselineRTK::ConstPtr &msg)
{
    rostime_to_gps::offsetMsg tmsg;
    tmsg.tSolution = msg->tSolution;
    tmsg.header.stamp = ros::Time::now();
    timerPub_.publish(tmsg);
}


} //end namespace


int main(int argc, char **argv)
{
    ros::init(argc, argv, "ttimer");
    ros::NodeHandle nh;

    try
    {
        ttimer::timerNode ttimer(nh);
        ros::spin();
    }
    catch(const std::exception &e)
    {
        ROS_ERROR("%s: %s", nh.getNamespace().c_str(), e.what());
        return 1;
    }
    return 0;
}
