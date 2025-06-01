#pragma once
#include <string>
#include <unordered_map>
#include "Device.h"

class Controller {
private:
	//Stores devices using name as the key. Much faster look up time with constant O(1) complexity.
	std::unordered_map<std::string, Device> devices;


public:



	//Adds a device to the network. Adds new entries to the map.
	void addDevice(const std::string& deviceName);

	//Connects two devices as neighbors. Using Device::addneighbor at both ends.
	void connectDevices(const std::string& name1, const std::string& name2);

	//Getter for debugging or simulation purposes. Returns just a pointer, safe if the device is not found.
	const Device* getDevice(const std::string& name) const;
};