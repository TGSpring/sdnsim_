#pragma once
#include <string>
#include <vector>

/**
 * @class Device
 * @brief Represents a network device (like a router or switch) in the SDN simulation.
 *
 * Stores device name, neighbors, and active state.
 */
class Device {
private:
    std::string name; /**< Name of the device (used as identifier). */
    std::vector<std::string> neighbors; /**< List of names of neighboring devices. */
    bool active = false; /**< Tracks whether the device is active or inactive. */

public:
    /**
     * @brief Constructs a Device with the given name.
     * @param deviceName Name to assign to this device.
     */
    Device(const std::string& deviceName);

    /**
     * @brief Gets the name of the device.
     * @return A copy of the device name.
     */
    std::string getName() const;

    /**
     * @brief Gets a reference to the list of neighbors.
     * @return Const reference to the vector of neighbor names.
     */
    const std::vector<std::string>& getNeighbors() const;

    /**
     * @brief Adds a neighbor to this device.
     * @param neighborName The name of the neighboring device to connect.
     */
    void addNeighbor(const std::string& neighborName);

    /**
     * @brief Checks if the device is currently active.
     * @return True if active, false if inactive.
     */
    bool isActive() const;

    /**
     * @brief Sets the device's active status.
     * @param status True to activate, false to deactivate.
     */
    void setActive(bool status);
};
