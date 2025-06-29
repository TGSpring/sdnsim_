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


	//Adding sendPacket Function. No idea how to do this. Should be fun.
	//Declared the method here so other files or the compiler during linkage, knows it exists.
	void sendPacket(const std::string& src, const std::string& dest, const std::string& payload);

	//Non const getter for turning on and off devices
	Device* getDevice(const std::string& name);

};