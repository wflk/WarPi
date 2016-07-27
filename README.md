#WarPi<br />
[![Build Status](http://eberlein.io:8080/buildStatus/icon?job=WarPi)](http://eberlein.io:8080/job/WarPi)
###What is it?<br />
Basically a All-in-One Box for your Car.<br />
###Sounds sketchy. Whats exactly in it?<br />
Short description of all files:<br />
#####WarPi/Database:<br />
For the connection with the CouchDB. (Storage of GPS/WiFi Logs)<br />
#####WarPi/GPS:<br />
GPS.* is the Object for the Storage of all the GPS information's.<br />
GPSMonitor.* is the threaded Function, which fills the GPS Object's information's.<br />
#####JSON:<br />
https://github.com/nlohmann/json<br />
The src/json.hpp from the above Project.<br />
#####Manager:<br />
Manager.* is the Object for all switches used by the threaded Function below.<br />
ManagerFunction.* is the threaded Function, which manages everything.<br />
#####WiFi:<br />
WiFi.* is the Object for the Storage of the WiFi Scans.<br />
WiFiMonitor.* is the threaded Function, which manages connecting, Wardriving, etc.<br />

###Ok, But what do I need to run it?<br />
Needs GCC >= 4.9
#####RestClient:<br />
git clone https://github.com/mrtazz/restclient-cpp<br />
cd restclient-cpp/ && ./autogen.sh && ./configure && make && sudo make install<br />
<br />
For connecting with the CouchDB Rest API.<br />
#####jsoncpp:<br />
git clone https://github.com/open-source-parsers/jsoncpp<br />
cd jsoncpp && mkdir build && cmake .. && make && make install<br />
<br />
For searching data with/in the Database (Since CouchDB stores its stuff in json format)
#####libiw-dev:<br />
sudo apt-get install libiw-dev<br />
Overall WiFi interaction.<br />
#####libboost-dev:<br />
sudo apt-get install libboost-all-dev<br />
For threading.
#####gpsd/libgps-dev:<br />
sudo apt-get install gpsd libgps-dev<br />
Overall GPS interaction.<br />
<br />
Uses these devices: (not needed, but recommended)<br />
A WiFi dongle.<br />
A GPS dongle.<br />
(Small) Cameras<br />
If a Device is missing, the program will just disable the modules that use that device by itself.<br />

###Heyy, that's pretty good.<br />
#####How can I help?<br />
Report Bugs, open a push request, just any useful contribution should get accepted.<br />
#####What's TODO:<br />
WiFi:<br />
->Karma HotSpot<br />
->Usage Lock in WiFi Class<br />
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
// Code is ugly. No h8 pls b0ss.
