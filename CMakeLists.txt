cmake_minimum_required(VERSION 2.8.3)
project(ethernetip_ros)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  odva_ethernetip
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
    roscpp
    odva_ethernetip
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############


