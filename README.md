## bittle-walker
ROS package for Gazebo simulation for a bittle robot and gait generation in the future

# Current State:
- Working in gazebo
- ~~Sliding behavior when trying to get up on legs~~
- ~~need to fix contact point friction values~~
- ~~joint control gui is available, but does not publish data to gazebo~~
- Effort PID controller roughly working, but could use tuning with higher joint effort limits
- Working with position controller and position based effort controller
- ~~Need to write inverse kinematics calculation for left and right side legs~~
- trajectory generation given joint angle waypoints - will probably use a trajectory generator
- step timing for walking, trotting, running
- PSOPT for trajectory optimization, IPOPT for nonlinear programming, both open source for c++
- look into making leg contact points true cylinders in collision meshes for better stability
  - currently blocky pieces with sharp edges

# Dependencies:
- ROS Noetic on Ubuntu 20.04
  - Requires full download to work with Gazebo
- ros-noetic-ros-control
- just clone it and try to run `roslaunch quad_walker gazebo.launch` and see what crashes
