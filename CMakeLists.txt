CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(WarPi)

FIND_PACKAGE(Boost 1.54 COMPONENTS thread filesystem REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

FIND_PACKAGE(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wl,--no-as-needed -ljsoncpp -lcurl -lgps -liw -pthread -ldl -lutil")

SET(SOURCE_FILES main.cpp Manager/Manager.cpp Manager/Manager.h Client/Client.cpp Client/Client.h WiFi/WiFi.cpp WiFi/WiFi.h GPS/GPS.cpp GPS/GPS.h Database/Database.cpp Database/Database.h Eve/Eve.cpp Eve/Eve.h)
ADD_EXECUTABLE(WarPi ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(WarPi ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} restclient-cpp jsoncpp iw gps dl pthread util)

INSTALL(TARGETS WarPi
        RUNTIME DESTINATION bin)

INSTALL(FILES config.json
        DESTINATION /etc/WarPi)