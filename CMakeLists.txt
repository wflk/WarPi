cmake_minimum_required(VERSION 3.5)
project(WarPi)

FIND_PACKAGE(Boost 1.54 COMPONENTS thread REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ljsoncpp -lcurl -lgps -liw")

set(SOURCE_FILES main.cpp GPS/GPS.cpp GPS/GPS.h Database/Database.cpp Database/Database.h GPS/GPSObject.cpp GPS/GPSObject.h Manager/ManagerObject.cpp Manager/ManagerObject.h Manager/Manager.cpp Manager/Manager.h WiFi/WiFiObject.cpp WiFi/WiFiObject.h WiFi/WiFi.cpp WiFi/WiFi.h Client/Client.cpp Client/Client.h Client/ClientObject.cpp Client/ClientObject.h)
add_executable(WarPi ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(WarPi ${Boost_LIBRARIES} restclient-cpp jsoncpp iw gps)
