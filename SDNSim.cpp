// SDNSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Controller.h"

int main()
{
	Controller control;

	//Adding devices TEST
	control.addDevice("Router");
	control.addDevice("Switch");
	control.addDevice("Firewall");

	//Connect said devices TEST
	control.connectDevices("Router", "Switch");

	//Disconnecting Firewall for packet test.
	//control.connectDevices("Switch", "Firewall");

	std::cout << "\n--- Packet Tests ---\n";

	//Valid
	control.sendPacket("Router", "Switch", "Ping");

	//Invalid. Destination is not a neighbor.
	control.sendPacket("Router", "Firewall", "Ping");

	//Invalid. Source does not exist.
	control.sendPacket("Ghost", "Switch", "Ping");

	//Invalid. Destination doesn't exist
	control.sendPacket("Router", "Void", "Ping");

	//Print device neighbors TEST
	for (const auto& deviceName : { "Router", "Switch", "Firewall" }) {
		const Device* device = control.getDevice(deviceName);
		if (device) {
			std::cout << device->getName() << " neighbors: ";
			for (const auto& neighbor : device->getNeighbors()) {
				std::cout << neighbor << " ";
			}
			std::cout << "\n";
		}
		else {
			std::cout << deviceName << " Not found.\n";
		}
	}
	return 0;
}

