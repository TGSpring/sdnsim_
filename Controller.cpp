#include "Controller.h"
#include <iostream>
#include <algorithm>

/**
* @brief Retrieves a const pointer to a device by name.
* @param name Name of the device to search for.
* @return Pointer to the device if found, nullptr otherwise.
*/

const Device* Controller::getDevice(const std::string& name) const {
	auto it = devices.find(name);
	return (it != devices.end()) ? &it->second : nullptr;
}
/**
* @brief Retrieves a modifiable pointer to a device by name.
* @param name Name of the device.
* @return Mutable pointer to device if found, nullptr otherwise.
*/

Device* Controller::getDevice(const std::string& name) {
	auto it = devices.find(name);
	return (it != devices.end()) ? &it->second : nullptr;
}

/**
* @brief Adds a device to the controller's map if it doesn't already exist.
* Uses emplace to construct in-place and avoid copy overhead.
* @param name Name of the device to add.
*/
void Controller::addDevice(const std::string& name) {
	if (devices.find(name) == devices.end()) {
		devices.emplace(name, Device(name));
	}
}

/**
* @brief Connects two devices bidirectionally as neighbors.
* Adds each device to the other's neighbor list if both exist.
* @param name1 First device name.
* @param name2 Second device name.
*/
void Controller::connectDevices(const std::string& name1, const std::string& name2) {

	auto it1 = devices.find(name1);
	auto it2 = devices.find(name2);


	if (it1 != devices.end() && it2 != devices.end()) {

		it1->second.addNeighbor(name2); 
		it2->second.addNeighbor(name1); 
	}
	else {
		std::cerr << "Error: One or both of the devices is not found\n";
	}

}

/**
* @brief Sends a simulated packet from one device to another.
* 
* This function checks that both the source and destination devices:
* - Exist in the network
* - Are currently active
* - Are directly connected (neighbors)
* 
* If all checks pass, the packet is "sent" (printed to stdout). Otherwise,
* appropriate error messages are logged to stderr.
* 
* @param src The name of the sourcr device.
* @param dest The name of the destination device.
* @param payload The content/data of the simulated packet.
*/
void Controller::sendPacket(const std::string& src, const std::string& dest, const std::string& payload) {


	std::cout << "Controller attempting to send packet..." << std::endl;

	auto itSrc = devices.find(src);
	auto itDest = devices.find(dest);

	//Step 1: Verify both devices exist.
	if (itSrc == devices.end() || itDest == devices.end()) {
		std::cerr << "Packet send error: one or both devices not founds.\n";
		return;
	}

	//Step 2: Check if devices are active.
	if (!itSrc->second.isActive()) {
		std::cerr << src << " is currently inactive.\n";
		return;
	}
	else {
		std::cout << src << " is active. Preparing to send packet..." << std::endl;
	}

	if (!itDest->second.isActive()) {
		std::cerr << dest << " is currently inactive.\n";
	}
	else {
		std::cout << dest << " is active. Packet destination valid." << std::endl;
	}

	//Step 3: Check neighbor relationship.
	const std::vector<std::string>& neighbors = itSrc->second.getNeighbors();
	if (std::find(neighbors.begin(), neighbors.end(), dest) != neighbors.end()) {
		std::cout << "Packet from " << src << " to " << dest << ": " << payload << std::endl;
	}
	else {
		std::cerr << "Packet send error: " << dest << " is not a neighbor of " << src << "\n";
	}

}