#include "Device.h"
#include <iostream>


//Constructor, creates new device.
// name(deviceName) initializer list. 
// Creates private member name with the value passed in deviceName directly.
//Remains empty because initilization is done in the list.
Device::Device(const std::string& deviceName) : name(deviceName) {

}

//Getter for device name. Returns copy and uses string to not modify.
//String_view would be the better option for something at scale.
std::string Device::getName() const {
	return name;

}


//Getter for neighbors vector
//Returns a constant reference to the neighbors vector.
const std::vector<std::string>& Device::getNeighbors() const {
	return neighbors;
}


//Adds new neighbor to this device.
//Appends the new neighbor to the vector of neighbors.
void Device::addNeighbor(const std::string& neighborName) {
	neighbors.push_back(neighborName);
}

bool Device::isActive() const {
	return active;
}

void Device::setActive(bool status) {
	active = status;
}