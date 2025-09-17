

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
#include "loadTopFile.h"



// Forward Declare the function from loadFromTopologyFile.cpp
void loadAndPrintTopology(Controller& control, const std::string& filename);

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

	// Load devices and links from file.
	loadAndPrintTopology(control, "topology.txt");

	// Packet tests based on loaded topology.
	control.sendPacket("Router", "Switch", "Ping");
	control.sendPacket("Router", "Firewall", "Ping");
	control.sendPacket("Router", "DownLink", "Ping");

	control.clearAllDevices();

	if (control.getAllDevices().empty()) {
		std::cout << "All devices cleared successfully." << std::endl;

	}

	if (control.getDevice("Router") == nullptr) {
		std::cout << "Router not found after clearing, as expected." << std::endl;
	}

	return 0;
}
