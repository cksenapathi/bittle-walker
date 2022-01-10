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
- theres a segfault somewhere in the inv kin code yikes


# Dependencies:
- ROS Noetic on Ubuntu 20.04
- ros-noetic-ros-control
- just clone it and try to run `roslaunch quad_walker gazebo.launch` and see what crashes
