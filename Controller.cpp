#include "Controller.h"
#include <iostream>
#include <algorithm>

/*
* Finds device by name in unordered_map called Devices.
* If found, returns a pointer to the device (Device*)
* If not found, returns nullptr.
*/

const Device* Controller::getDevice(const std::string& name) const {
	auto it = devices.find(name);
	if (it != devices.end()) {
		return &it->second;
	}
	else {
		return nullptr;
	}
}

/*
* Adds a new device only if it's not already in the map (checks with find vs end).
* Uses emplace to construct the device directly in the map for efficiency.
*/
void Controller::addDevice(const std::string& name) {
	if (devices.find(name) == devices.end()) {
		devices.emplace(name, Device(name));
	}
}

/*
* Finds both devices by their names.
* If both exist, adds each other as neighbors (bidirectional connection).
* Otherwise, prints an error message to cerr.
*/
void Controller::connectDevices(const std::string& name1, const std::string& name2) {
	//Auto tells the compiler to deduce the variable's type for you based on the right-hand side of the expression.
	auto it1 = devices.find(name1);
	auto it2 = devices.find(name2);

	//This bit was a learning experience. Using
	//.end to find the value while using !=.
	//Tricky to me at first, great now.
	if (it1 != devices.end() && it2 != devices.end()) {
		//both of the devices exist, connect.
		it1->second.addNeighbor(name2); //name2 is neighbor of name1
		it2->second.addNeighbor(name1); //name1 is neighbor of name2
	}
	else {
		std::cerr << "Error: One or both of the devices is not found\n";
	}

}
//Adding sendPacket Function. No idea how to do this. Should be fun.
//Learned here about why I need to be adding the Controller::, tells the compiler this function belongs to this class.
//If I defined this inside of the connectDevices function, I would be nesting functions, which is not allowed in c++.
//They have to be defined inside the body of the header file or outside with the qualified (Controller) name.
void Controller::sendPacket(const std::string& src, const std::string& dest, const std::string& payload) {

	//Using std::endl inserts a new line while flushing a buffer, slightly slower performance, but ensures it prints.
	std::cout << "Controller attempting to send packet..." << std::endl;

	auto itSrc = devices.find(src);
	auto itDest = devices.find(dest);

	//Step 1: Check both devices exist.
	if (itSrc != devices.end() && itDest != devices.end()) {
		//Safe to proceed with sending packet.
		//Step 2: Check if dest is a neighbor of src.
		const std::vector<std::string>& neighbors = itSrc->second.getNeighbors();
		if (std::find(neighbors.begin(), neighbors.end(), dest) != neighbors.end()) {
			//Step 3: Packet is allowed to be sent.
			std::cout << "Packet from " << src << " to " << dest << ": " << payload << std::endl;
		}
		else {
			std::cerr << "Packet send error: " << dest << " is not a neighbor of " << src << "\n";
		}
	}
	else {
		std::cerr << "Packet send error: one or both devices not found.\n";
	}

}