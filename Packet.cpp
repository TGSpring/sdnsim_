#include "Packet.h"

/**
* @brief Constructs a packet with a source, destination, and payload.
*
* Initializes a network packet used in SDNSim to simulate communication between devices.
*
* @param src Name of the device sending the packet.
* @param dest Name of teh device intended to recieve the packet.
* @param data The content or message being transmitted.
*/
Packet::Packet(const std::string& src, const std::string& dest, const std::string& data)
	: source(src), destination(dest), payload(data) {
}