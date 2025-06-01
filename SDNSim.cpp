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
	control.connectDevices("Switch", "Firewall");

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

