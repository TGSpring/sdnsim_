#include "Controller.h"
#include <iostream>

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