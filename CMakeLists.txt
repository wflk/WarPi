cmake_minimum_required(VERSION 3.5)
project(WarPi)

FIND_PACKAGE(Boost 1.54 COMPONENTS thread REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ljsoncpp -lcurl -lgps -liw")

set(SOURCE_FILES main.cpp Manager/Manager.cpp Manager/Manager.h Client/Client.cpp Client/Client.h WiFi/WiFi.cpp WiFi/WiFi.h GPS/GPS.cpp GPS/GPS.h Database/Database.cpp Database/Database.h)
add_executable(WarPi ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(WarPi ${Boost_LIBRARIES} restclient-cpp jsoncpp iw gps)
