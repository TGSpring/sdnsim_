

/*!
 * \mainpage SDNSim Documentation
 *
 * # SDNSim Project
 *
 * SDNSim is a C++ software-defined networking simulation that models a centralized
 * controller managing network devices and packet routing.
 *
 * ## Features
 * - Device management (add, connect, monitor)
 * - Packet sending and routing
 * - Fault detection and network simulation
 *
 * ## Build and Run
 * - Use Visual Studio solution `SDNSim.sln` to build.
 * - Run the resulting executable from the `Debug` or `Release` folder.
 *
 * ## Viewing Documentation
 * Generate docs using Doxygen by running:
 * ```
 * doxygen Doxyfile
 * ```
 * Then open `docs/html/index.html` in your browser.
 */

 // SDNSim.cpp : This file contains that main function. Program execution begins and ends here.

#include <iostream>
#include "Controller.h"

/**
* @brief Entry point for the SDNSim application.
*
* Sets up the network devices and connections, then runs a series of packet sending tests, including
* handling invalid scenarios and device active states.
*
* @return int Exit status code (0 for success).
*/

int main() {
	Controller control;

	// --- Adding Devices (Hard-coded) ---
	control.addDevice("Router");
	control.addDevice("Switch");
	control.addDevice("Firewall");
	control.addDevice("DownLink"); ///< Used to test active/inactive behavior

	// --- Connecting Devices ---
	control.connectDevices("Router", "Switch");
	control.connectDevices("Router", "DownLink");
	// Note: Firewall intentionally disconnected for testing

	std::cout << "\n Packet Tests [ HARD CODED ] \n";

	// --- Packet Sending Tests ---

	//1. Valid date packet: Router -> Switch
	control.sendPacket("Router", "Switch", "Ping");

	// 2. Invalid: Destination not a neighbor (Router -> Firewall)
	control.sendPacket("Router", "Firewall", "Ping");

	// 3. Invalid: Source device doesn't exist
	control.sendPacket("Ghost", "Switch", "Ping");

	// 4. Invalid: Destination device doesn't exist
	control.sendPacket("Router", "Void", "Ping");

	// --- Testing Active/Inactive Status ---

	// Set DownLink device to inactive
	Device* downLink = control.getDevice("DownLink");
	if (downLink) {
		downLink->setActive(false);
	}

	// Set Router device to active (just in case)
	Device* router = control.getDevice("Router");
	if (router) {
		router->setActive(true);
	}

	// Attempt sending packet to inactive DownLink
	control.sendPacket("Router", "DownLink", "Test message to offline device");

	// --- Additional test: ensuring Router is active again ---
	if (router) {
		router->setActive(true);
	}


	// --- Print neighbors of devices for verification ---
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
			std::cout << deviceName << " not found.\n";
		}
	}

	// --- Load Topology from File ---
	std::cout << "\n--- Loading from topology from file ---\n";
	control.loadTopologyFromFile("topology.txt");

	std::cout << "\nNeighbors after topology file loaded:\n";
	for (const auto& name : { "Router", "Switch", "Firewall", "DownLink" }) {
		const Device* dev = control.getDevice(name);
		if (dev) {
			std::cout << dev->getName() << " neighbors: ";
			for (const auto& n : dev->getNeighbors()) std::cout << n << " ";
			std::cout << "\n";
		}
	}
	// --- Packet Tests (Loaded Topology) ---
	std::cout << "\n--- Packet Tests (Loaded Topology) ---\n";
	control.sendPacket("Router", "Switch", "Ping");
	control.sendPacket("Router", "Firewall", "Ping");
	control.sendPacket("Router", "DownLink", "Ping");

	return 0;
}
