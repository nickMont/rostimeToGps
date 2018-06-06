cmake_minimum_required(VERSION 2.8.3)
project(rostime_to_gps)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  std_msgs
  tf2_ros
  cmake_modules
  gbx_ros_bridge_msgs
)

find_package(Eigen REQUIRED)

add_message_files(
  FILES
  offsetMsg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  gbx_ros_bridge_msgs
)

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS gbx_ros_bridge_msgs
    DEPENDS Eigen
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

add_executable(timer_node src/timer.cpp)
add_dependencies(timer_node gbx_ros_bridge_msgs_gencpp)
add_dependencies(timer_node gbx_ros_bridge_msgs)
add_dependencies(timer_node timer_node_generate_messages_cpp)
target_link_libraries(timer_node ${catkin_LIBRARIES})

