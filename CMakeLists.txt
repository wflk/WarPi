cmake_minimum_required(VERSION 3.5)
project(WarPi)

FIND_PACKAGE( Boost 1.54 COMPONENTS thread REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lgps -lcurl")

set(SOURCE_FILES main.cpp GPS/GPSMonitor.cpp GPS/GPSMonitor.h Database/Database.cpp Database/Database.h GPS/GPS.cpp GPS/GPS.h Manager/Manager.cpp Manager/Manager.h Manager/ManagerFunction.cpp Manager/ManagerFunction.h WiFi/WiFi.cpp WiFi/WiFi.h WiFi/WiFiMonitor.cpp WiFi/WiFiMonitor.h)
add_executable(WarPi ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( WarPi ${Boost_LIBRARIES} )