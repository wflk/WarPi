#WarPi<br />
[![Build Status](http://eberlein.io:8080/buildStatus/icon?job=WarPi)](http://eberlein.io:8080/job/WarPi)
###What is it?<br />
Basically a All-in-One Box for your Car.<br />
###Sounds sketchy. Whats exactly in it?<br />
Short description of all files:<br />
#####WarPi/Database:<br />
For the connection with the CouchDB. (Storage of GPS/WiFi Logs)<br />
#####WarPi/GPS:<br />
GPS.* -> used for the overall GPS functionality.<br />
#####JSON:<br />
https://github.com/nlohmann/json<br />
The src/json.hpp from the above Project.<br />
#####Manager:<br />
Manager.* -> Controls the whole thingy.<br />
#####WiFi:<br />
WiFi.* -> used for the overall WiFi functionality.<br />
###Ok, But what do I need to run it?<br />
Either you use the dependencies.sh script or follow the steps below.<br />
#####Libboost:<br />
apt-get install libboost-all-dev
#####RestClient:<br />
git clone https://github.com/mrtazz/restclient-cpp<br />
cd restclient-cpp/ && ./autogen.sh && ./configure && make && sudo make install<br />
<br />
For connecting with the CouchDB Rest API.<br />
#####RapidJSON:<br />
git clone https://github.com/miloyip/rapidjson<br />
cd rapidjson && mkdir build && cmake .. && make && make install<br />
<br />
For searching data with/in the Database and parsing the configuration file.
#####libiw-dev:<br />
sudo apt-get install libiw-dev<br />
Overall WiFi interaction.<br />
#####gpsd/libgps-dev:<br />
sudo apt-get install gpsd libgps-dev<br />
Overall GPS interaction.<br />
<br />
Uses these devices: (not needed, but recommended)<br />
A WiFi dongle.<br />
A GPS dongle.<br />
(Small) Cameras (numberplate recognition is not yet implemented)<br />

###Heyy, that's pretty good.<br />
#####How can I help?<br />
Report Bugs, open a push request, just any useful contribution should get accepted.<br />
#####What's TODO:<br />
WiFi:<br />
->Karma HotSpot<br />
->Authentication with known & open Networks<br />
<br />
Networking:<br />
->Host Discovery<br />
->Spoofing<br />
<br />
Client:<br />
->On Internet: Connect to main Node and sync.<br />
->Get cmd's and set switches accordingly.<br />
<br />
GPS:<br />
->Navigation with GPS (Map Rendering & Overlay)<br />
<br />
Camera:<br />
->Parking System (Distance measurement, etc.)<br />
->Number Plate Recognition & Location logging<br />
<br />
Code Documentation<br />
<br />
Whatever else comes to my/your head and seems usable.<br />
<br />

###Errors:
error while loading shared libraries: librestclient-cpp.so.1: cannot open shared object file: No such file or directory:<br />
ln -s /usr/local/lib/librestclient-cpp.so.1 /usr/lib/<br />

// Code is ugly. No h8 pls b0ss.
