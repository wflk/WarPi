#!/usr/bin/env bash
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root"
   exit 1
fi

echo "[ * ] Updating System"
apt-get update > /dev/null 2>&1
echo "[ * ] Upgrading System"
apt-get upgrade -y > /dev/null 2>&1
echo "[ * ] Installing wget, bzip2, tar, git"
apt-get install wget bzip2 tar git -y > /dev/null 2>&1

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

echo "[ * ] Installing dependencies for libboost"

echo "[ * ] Downloading and unpacking libboost 1.61"
wget https://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.bz2
bunzip2 boost_1_61_0.tar.bz2 > /dev/null 2>&1
tar xf boost_1_61_0.tar > /dev/null 2>&1

echo "[ * ] Boostrapping"
cd boost_1_61_0
./boostrap.sh --libdir=/usr/local/lib --includedir=/usr/local/include > /dev/null 2>&1
echo "[ * ] Building and installing (this will take quiet a while)"
./bjam > /dev/null 2>&1
./bjam install > /dev/null 2>&1
echo "[ + ] Done. libboost should be installed now."
echo "[ * ] Cleaning up.."
cd /tmp/
rm -rf boost* > /dev/null 2>&1

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