cmake_minimum_required(VERSION 2.8.3)
project(simple_communication)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(streamer src/streamer.cpp)
target_link_libraries(streamer ${catkin_LIBRARIES})

add_executable(manipulator src/manipulator.cpp)
target_link_libraries(manipulator ${catkin_LIBRARIES})

