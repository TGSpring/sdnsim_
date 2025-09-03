#include <iostream>
#include "Controller.h"
#include "loadTopFile.h"
/**
* @brief Loads a network topology file, prints device information, and runs basic packet tests.
* 
* This function performs the following steps:
* 1. Loads a topology using the provided Controller instance.
* 2. Prints all devices that were loaded.
* 3. Prints neighbors for each device.
* 4. Runs optional packet tests to verify connectivity between devices.
* 
* @param control Reference to a Controller instance used to manage devices and links.
* @param filename Path to the topology file to load.
*/
void loadAndPrintTopology(Controller& control, const std::string& filename) {
    control.loadTopologyFromFile(filename);

    // Get all devices
    const auto& devices = control.getAllDevices();

    // Print all devices
    std::cout << "--- Devices Loaded ---\n";
    for (const auto& [name, device] : devices) {
        std::cout << name << "\n";
    }

    // Print neighbors
    std::cout << "\n--- Device Neighbors ---\n";
    for (const auto& [name, device] : devices) {
        std::cout << name << " neighbors: ";
        if (device.getNeighbors().empty()) {
            std::cout << "(no neighbors)";
        }
        else {
            for (const auto& neighbor : device.getNeighbors()) {
                std::cout << neighbor << " ";
            }
        }
        std::cout << "\n";
    }

    // Optional: run packet tests only if devices exist
    std::cout << "\n--- Packet Tests (Loaded Topology) ---\n";

    struct PacketTest {
        std::string src;  /**< Source device name */
        std::string dst;  /**< Destination device name */
        std::string msg;  /**< Message to send */
    };

    // Predefined packet tests
    PacketTest tests[] = {
        {"Router", "Switch", "Ping"},
        {"Router", "Firewall", "Ping"},
        {"Router", "DownLink", "Ping"}
    };

    for (const auto& test : tests) {
        if (devices.find(test.src) != devices.end() &&
            devices.find(test.dst) != devices.end()) {
            control.sendPacket(test.src, test.dst, test.msg);
        }
        else {
            std::cout << "Skipping packet from '" << test.src << "' to '"
                << test.dst << "' - one or both devices not found\n";
        }
    }
}
