# ouster_example

Commands :

// Start the Lidar (Ouster)
sudo systemctl stop dnsmasq
sudo systemctl start dnsmasq

journalctl -fu dnsmasq

// Launch Lidar data acquisition: arg1 : ip_lidar, arg2 : ip_computer (desitnation)
$ roslaunch ouster_ros os1.launch os1_hostname:=192.168.1.123 os1_udp_dest:=192.168.1.1

// Record a rosbag from LIDAR OUSTER:
$ rosbag record /os1_node/points /os1_node/imu


// If issue with cartographer:
$ source install_isolated/setup.bash

// Cartographer:
inside cartographer
$ catkin_make_isolated --install --use-ninja

// Test rosbag:
$ cartographer_rosbag_validate -bag_filename office_map3.bag

// terminate with mapping creation:
$ rosservice call /finish_trajectory 0
// next step:
rosservice call /write_state "{filename: '/home/jonathan/map_catkin_ws/office_map4.bag.pbstream'}"

// Visulize the map
roslaunch cartographer_ros visualize_pbstream.launch pbstream_filename:=/home/jonathan/Download/vid_output.bag.pbstream

// Write a map:
$ roslaunch cartographer_ros assets_writer_my_robot_2d.launch \bag_filenames:=${HOME}/map_catkin_ws/office_map3.bag \pose_graph_filename:=${HOME}/Downloads/office_map3.bag.pbstream
$ roslaunch cartographer_ros assets_writer_my_robot_2d.launch \bag_filenames:=/home/jonathan/map_catkin_ws/office_map4.bag \pose_graph_filename:=/home/jonathan/map_catkin_ws/office_map4.bag.pbstream

$ roslaunch cartographer_ros demo_my_robot_2d.launch bag_filename:=/home/jonathan/map_catkin_ws/tryNewTime.bag

// Try to locate from a rosbag
$ roslaunch cartographer_ros demo_my_robot_2d_localization.launch \
   load_state_filename:=/home/jonathan/map_catkin_ws/office_map4.bag.pbstream \
   bag_filename:=/home/jonathan/map_catkin_ws/findMe_office_map4.bag

   roslaunch cartographer_ros demo_backpack_2d_localization.launch \
   load_state_filename:=${HOME}/Downloads/b2-2016-04-05-14-44-52.bag.pbstream \
   bag_filename:=${HOME}/Downloads/b2-2016-04-27-12-31-41.bag

// WORKS
roslaunch cartographer_ros demo_my_robot_2d_localization.launch    load_state_filename:=/home/jonathan/map_catkin_ws/office_map4.bag.pbstream bag_filename:=/home/jonathan/map_catkin_ws/findMe_office_map4.bag

// Cartographer-Ros
// Launch a real-time localization
- Open three terminal,
- Go in map_catkin_ws in the two first and catkin_ws_kyb for the last one
- Source them,
- And:
$ roslaunch ouster_ros os1.launch os1_hostname:=192.168.1.123 os1_udp_dest:=192.168.1.1
$ rosbag play --clock /home/jonathan/map_catkin_ws/findMe_office_map4.bag
and set the rosbag in pause and launch the last command in the last terminal on map_catkin_ws
$ roslaunch cartographer_ros demo_my_robot_2d_localization.launch    load_state_filename:=/home/jonathan/map_catkin_ws/office_map4.bag.pbstream

After a few second, you can see the position of the robot.
