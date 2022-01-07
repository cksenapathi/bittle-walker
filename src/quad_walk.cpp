#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
//#include <tf2_msgs/TFMessage>
#include <vector>

// Right side angles need to be negative, left side will be positive
// angle order goes {lbk, lbs, lfk, lfs, rbk, rbs, rfk, rfs}

const double PI = 3.141592;

int main(int argc, char** argv){

  ros::init(argc, argv, "controller");

  ros::NodeHandle n;
  ros::Rate rate(50);

  ros::Publisher joints_pub = n.advertise<std_msgs::Float64MultiArray>("/bittle/joints_controller/command",1000);

  std_msgs::Float64MultiArray joint_array;

  joint_array.data = std::vector<double>({1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6});
  std_msgs::MultiArrayDimension dim;
  dim.label = "dim1";
  dim.size = 8;
  dim.stride = 1;
  joint_array.layout.data_offset = 0;
  joint_array.layout.dim = std::vector<std_msgs::MultiArrayDimension>({dim});

  while (ros::ok()){
    joints_pub.publish(joint_array);
    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}
