#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
#include <gbx_ros_bridge_msgs/SingleBaselineRTK.h>
#include <cmath>
#include <rostime_to_gps/offsetMsg.h>

namespace ttimer
{

class timerNode
{
 public:
    timerNode(ros::NodeHandle &nh);

    void singleBaselineRTKCallback(const gbx_ros_bridge_msgs::SingleBaselineRTK::ConstPtr &msg);

 private:

    ros::Publisher timerPub_;
    ros::Subscriber rtkSub_;

};

}