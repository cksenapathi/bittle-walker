#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
//#include <tf2_msgs/TFMessage>
#include <vector>
#include <cmath>

// Right side angles need to be negative, left side will be positive
// angle order goes {lbk, lbs, lfk, lfs, rbk, rbs, rfk, rfs}


const double S = .5; // shoulder length; meters
const double K = .54; // knee length; meters
const double PI = 3.141592;


std::vector<double> ik_left(double x, double y){
  std::vector<double> angles(2);
  angles[0] = asin((x*x + y*y - S*S - K*K)/(2*S*K));
  double c1 = sin(angles[0]);
  double c2 = cos(angles[0]);
  double KC = S + K*c1;
  angles[1] = atan((y*K*c2 - x*KC)/(x*K*c2 + y*KC));
  return angles;
}

std::vector<double> ik_right(double x, double y){
  std::vector<double> angles(2);
  angles[0] = asin((S*S + K*K - x*x - y*y)/(2*S*K));
  double c1 = sin(angles[0]);
  double c2 = cos(angles[0]);
  double KC = S - K*c1;
  angles[1] = atan((-y*K*c2 - x*KC)/(y*KC - x*K*c2));
  ROS_INFO("sin theta = %f \n cos theta = %f",y*K*c2 + x*KC, x*K*c2 - KC*y);
  return angles;
}

// std::vector<double>& repack(std::vector<double>& lb, std::vector<double>& lf, std::vector<double>& rb, std::vector<double>& rf){
//   std::vector<double> output(8);
//   output[0] = lb[0];
//   output[1] = lb[1];
//   output[2] = lf[0];
//   output[3] = lf[1];
//   output[4] = rb[0];
//   output[5] = rb[1];
//   output[6] = rf[0];
//   output[7] = rf[1];
//   return output;
// }

std::vector<double> cart_to_angle(std::vector<double>& legs_xy){
  std::vector<double> angles;
  std::vector<double> v = ik_left(legs_xy[0], legs_xy[1]);
  angles.insert(angles.end(), v.begin(), v.end());
  v = ik_left(legs_xy[2], legs_xy[3]);
  angles.insert(angles.end(), v.begin(), v.end());
  v = ik_right(legs_xy[4], legs_xy[5]);
  angles.insert(angles.end(), v.begin(), v.end());
  v = ik_right(legs_xy[6], legs_xy[7]);
  angles.insert(angles.end(), v.begin(), v.end());
  return angles;
}

int main(int argc, char** argv){

  ros::init(argc, argv, "controller");

  ros::NodeHandle n;
  ros::Rate rate(50);

  ros::Publisher joints_pub = n.advertise<std_msgs::Float64MultiArray>("/bittle/effort_controller/command",1000);

  std_msgs::Float64MultiArray joint_array;

  // Generate positions for foot endings
  // lbx, lby, lfx, lfy, rbx, rby, rfx, rfy
  std::vector<double> leg_xy({0, -.7, 0, -.7, 0, 0.7, 0, 0.7});
  // convert to angles
  // feed into joint_array data


  joint_array.data = cart_to_angle(leg_xy);
  std_msgs::MultiArrayDimension dim;
  dim.label = "dim1";
  dim.size = 8;
  dim.stride = 1;

  for(double d: joint_array.data){
    ROS_INFO("%f", d);
  }
  // joint_array.layout.data_offset = 0;
  // joint_array.layout.dim = std::vector<std_msgs::MultiArrayDimension>({dim});

  // joints_pub.publish(joint_array);
  // ros::Duration(3).sleep();

  // joint_array.data = std::vector<double>({0.3, 0.5, 0.3, 0.5, -0.3, -0.5, -0.3, -0.5});
  joint_array.layout.data_offset = 0;
  joint_array.layout.dim = std::vector<std_msgs::MultiArrayDimension>({dim});

  while (ros::ok()){
    joints_pub.publish(joint_array);
    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}
