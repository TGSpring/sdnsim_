#pragma once
#include <string>
#include <unordered_map>
#include "Device.h"

/**
 * @class Controller
 * @brief Central SDN controller that manages all devices and network logic.
 *
 * The Controller simulates a centralized decision-making component of a Software Defined Network.
 * It keeps track of all devices (e.g., routers, switches) and their relationships,
 * and provides core functionality like sending packets and checking status.
 */
class Controller {
private:
    /**
     * @brief Maps device names to Device objects for fast lookup.
     *
     * `unordered_map` gives O(1) average-time access for inserting and retrieving devices
     * by name. This allows the controller to quickly manage the network's state.
     */
    std::unordered_map<std::string, Device> devices;

public:
    /**
     * @brief Adds a new device to the network.
     *
     * If a device with the same name already exists, it will not be added again.
     *
     * @param deviceName The name of the device to add.
     */
    void addDevice(const std::string& deviceName);

    /**
     * @brief Connects two devices together as neighbors.
     *
     * This forms a bidirectional link between two existing devices.
     * Each device adds the other to its neighbor list.
     *
     * @param name1 The name of the first device.
     * @param name2 The name of the second device.
     */
    void connectDevices(const std::string& name1, const std::string& name2);

    /**
     * @brief Gets a const pointer to a device (read-only access).
     *
     * Useful for safely inspecting device state without modifying it.
     *
     * @param name The name of the device to retrieve.
     * @return Pointer to the device if found, nullptr otherwise.
     */
    const Device* getDevice(const std::string& name) const;

    /**
     * @brief Gets a modifiable pointer to a device.
     *
     * Allows toggling device state (e.g., turning on/off).
     * Use carefully, as it bypasses some encapsulation.
     *
     * @param name The name of the device to retrieve.
     * @return Pointer to the device if found, nullptr otherwise.
     */
    Device* getDevice(const std::string& name);

    /**
     * @brief Attempts to send a packet from one device to another.
     *
     * Validates existence, activity status, and neighbor relationship
     * before sending the packet.
     *
     * @param src The source device name.
     * @param dest The destination device name.
     * @param payload The message/data to be sent.
     */
    void sendPacket(const std::string& src, const std::string& dest, const std::string& payload);
};
