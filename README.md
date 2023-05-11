# choreonoid_ros_control_sample

- Based on https://qiita.com/FAL19/items/7b4a491e2399aa5cf7c9

- However, URDF for body and new ROS control plugin.

- Install  
  `$ws` means path of your work space.
  ```
  mkdir -p $ws/src
  cd $ws/src
  git clone https://github.com/MasutaniLab/choreonoid_ros_control_sample
  cd $ws
  catkin build
  ```

- Terminal 1
  ```
  cd $ws
  source devel/setup.bash
  roslaunch choreonoid_ros_control_sample bringup.launch
  ```

- Terminal 2
  ```
  cd $ws
  source devel/setup.bash
  roslaunch choreonoid_ros_control_sample display.launch 
  ```

- Terminal 3
  ```
  cd $ws
  source devel/setup.bash
  rosrun choreonoid_ros_control_sample sinewave_command 
  ```
