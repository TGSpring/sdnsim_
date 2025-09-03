#include "Controller.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

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

	if (name1 == name2) return; //No self-loop

	auto it1 = devices.find(name1);
	auto it2 = devices.find(name2);


	if (it1 != devices.end() && it2 != devices.end()) {
		//Only add if not already present.
		auto& neighbors1 = it1->second.getNeighbors();
		if (std::find(neighbors1.begin(), neighbors1.end(), name2) == neighbors1.end())
			it1->second.addNeighbor(name2);

		auto& neighbors2 = it2->second.getNeighbors();
		if (std::find(neighbors2.begin(), neighbors2.end(), name1) == neighbors2.end())
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
/**
 * @brief Loads network topology from a text file.
 *
 * Supports two sections in the file:
 * - `# Devices`: Each line is "DeviceName active|inactive"
 * - `# Links`: Each line is "Device1 Device2"
 *
 * Ignores blank lines, comments, self-loops, and duplicate connections.
 *
 * @param filename Path to the topology file.
 */

void Controller::loadTopologyFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open topology file: " << filename << std::endl;
		return;
	}

	enum class Section { None, Devices, Links };
	Section currentSection = Section::None;
	/*
	* Each line should have two device names separated by whitespace.
	* Use std::istringstream to split.
	*/

	std::string line;
	while (std::getline(file, line)) {
		// Trim leading whitespace
		line.erase(0, line.find_first_not_of(" \t\r\n"));
		// Trim trailing whitespace
		line.erase(line.find_last_not_of(" \t\r\n") + 1);


		if (line.empty() || line[0] == '#') {
			//Detect section headers.
			if (line.find("# Devices") != std::string::npos) currentSection = Section::Devices;
			else if (line.find("# Links") != std::string::npos) currentSection = Section::Links;
			continue;
		}
		std::istringstream iss(line);
		if (currentSection == Section::Devices) {
			std::string devName, state;
			if (!(iss >> devName >> state)) {
				std::cerr << "Invalid device line: " << line << std::endl;
				continue;
			}

			addDevice(devName);

			Device* dev = getDevice(devName);
			if (dev) {
				if (state == "active") dev->setActive(true);
				else if (state == "inactive") dev->setActive(false);
				else std::cerr << "Unknown state '" << state << " 'for device " << devName << std::endl;
			}
		}
		else if (currentSection == Section::Links) {
			std::string dev1, dev2;
			if (!(iss >> dev1 >> dev2)) {
				std::cerr << "Invalid link line: " << line << std::endl;
				continue;
			}

			if (dev1 == dev2) {
				std::cerr << "Warning: Ignoring self-loop for device " << dev1 << std::endl;
				continue;
			}

			addDevice(dev1);
			addDevice(dev2);

			//Avoid duplicate connections
			Device* d1 = getDevice(dev1);
			if (d1) {
				const auto& neighbors = d1->getNeighbors();
				if (std::find(neighbors.begin(), neighbors.end(), dev2) != neighbors.end()) {
					std::cerr << "Info: Skipping duplicate connection " << dev1 << " - " << dev2 << std::endl;
					continue;
				}
			}
			connectDevices(dev1, dev2);
		}
	}


	file.close();
	std::cout << "[INFO] Topology loaded from " << filename << std::endl;
}

/**
 * @brief Returns a const reference to all devices.
 *
 * Allows iteration over all devices without copying the map.
 *
 * @return const reference to the devices map.
 */
const std::unordered_map<std::string, Device>& Controller::getAllDevices() const {
	return devices;
}
