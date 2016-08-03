#!/usr/bin/env bash
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root"
   exit 1
fi

echo "[ * ] Updating System"
apt-get update > /dev/null 2>&1
echo "[ * ] Upgrading System"
apt-get upgrade -y > /dev/null 2>&1
echo "[ * ] Installing wget, bzip2, tar, git, screen"
apt-get install wget bzip2 tar git screen -y > /dev/null 2>&1

echo "[ * ] Installing other needed libraries"
apt-get install libiw-dev libcurl4-openssl-dev libgps-dev autoconf libtool -y > /dev/null 2>&1

echo "[ * ] Changing directory to '/tmp/'"
cd /tmp/

echo "[ * ] Downloading and unpacking CMake 3.6.0"
wget https://cmake.org/files/v3.6/cmake-3.6.0.tar.gz > /dev/null 2>&1
tar xf cmake-3.6.0.tar.gz > /dev/null 2>&1
echo "[ * ] Running ./configure, make and make install"
cd cmake*
./configure > /dev/null 2>&1
make > /dev/null 2>&1
make install > /dev/null 2>&1
echo "[ + ] CMake 3.6.0 should be installed now."
echo "[ * ] Cleaning up.."
cd /tmp/
rm -rf cmake* > /dev/null 2>&1
echo "[ * ] OK"

echo "[ * ] Cloning restclient-cpp"
git clone https://github.com/mrtazz/restclient-cpp.git > /dev/null 2>&1
cd restclient-cpp/
echo "[ * ] Installing restclient-cpp"
./autogen.sh > /dev/null 2>&1
./configure > /dev/null 2>&1
make > /dev/null 2>&1
make install > /dev/null 2>&1
echo "[ * ] Done. Cleaning up."
cd /tmp
rm -rf restclient-cpp/

echo "[ * ] Cloning jsoncpp"
git clone https://github.com/open-source-parsers/jsoncpp > /dev/null 2>&1
cd jsoncpp
echo "[ * ] Installing jsoncpp"
mkdir build
cd build
cmake .. > /dev/null 2>&1
make > /dev/null 2>&1
make install > /dev/null 2>&1
cd /tmp
echo "[ + ] Should be installed. Cleaning up."
rm -rf jsoncpp

echo "[ + ] Done installing dependencies"