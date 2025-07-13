#include "Device.h"
#include <iostream>

/**
* @brief Constructs a Device with the given name.
*
* Initializes the device with the specified identifier.
*
* @param deviceName The name assigned to this device.
*/

Device::Device(const std::string& deviceName) : name(deviceName) {

}


/**
* @brief Retrieves the name of the device.
*
* @return The name of the device as a string.
*/
std::string Device::getName() const {
	return name;

}

/**
* @brief Gets the list of neighboring device names.
*
* @return A const reference to a vector of neighbor names.
*/

const std::vector<std::string>& Device::getNeighbors() const {
	return neighbors;
}

/**
* @brief Adds a neighbor to this device's list.
*
* @param neighborName The name of the device to connect as a neighbor.
*/

void Device::addNeighbor(const std::string& neighborName) {
	neighbors.push_back(neighborName);
}

/**
* @brief Checks if the device is currently active.
*
* @return True if the device is active, false otherwise.
*/

bool Device::isActive() const {
	return active;
}

/**
* @brief Sets the device's active status.
*
* @param status True to mark the device as active, false for inactive.
*/

void Device::setActive(bool status) {
	active = status;
}