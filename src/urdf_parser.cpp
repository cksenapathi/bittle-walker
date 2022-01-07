// #include <urdf/model.h>
// #include "ros/ros.h"
//
// int main(int argc, char** argv){
//   ros::init(argc, argv, "my_parser");
//   if (argc != 2)
//     ROS_ERROR("Need a urdf file as argument");
//     return -1;
//   }
//   std::string urdf_file = argv[1];
//
//   urdf::Model model;
//   if (!model.initFile(urdf_file)){
//     ROS_ERROR("Failed to parse urdf file");
//     return -1;
//   }
//   ROS_INFO("Successfully parsed urdf file");
//
//   // std::shared_ptr<const urdf::Link> link = model.getLink("left_back_knee_joint");
//   // ROS_INFO("found link");
//
//   // ROS_INFO("gemotry type is mesh: %d", link->collision->geometry->type == urdf::Geometry::MESH);
//   //
//   // std::shared_ptr<const urdf::Mesh> collision_mesh = std::dynamic_pointer_cast<urdf::Mesh>(link->collision -> geometry);
//   // ROS_INFO("found link mesh");
//   // std::string filename = collision_mesh -> filename;
//   // ROS_INFO("found link mesh filename");
//   // double x = collision_mesh -> scale.x;
//   // double y = collision_mesh -> scale.y;
//   // double z = collision_mesh -> scale.z;
//   //
//   // ROS_INFO("link file name : %s", filename.c_str());
//   // ROS_INFO("link scale which is hopefully the dimensions gang gang: %f %f %f", x, y, z);
//   return 0;
// }
