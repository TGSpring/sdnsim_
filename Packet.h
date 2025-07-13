#pragma once
#include <string>
/**
* @class Packet
* @brief Represents a data packet in the SDN simulation.
*
* Contains source, destination, and payload information.
*/
class Packet {
public:
	std::string source;			/** < Name of the source device sending the packet. */
	std::string destination;	/** < Name of the destination device receiving the packet. */
	std::string payload;		/** < Content or message carried by the packet. */

	/**
	* @brief Constructs a packet with specified source, destination, and payload.
	* @param src The name of the sending device.
	* @param dest The name of the receiving device.
	* @param data The content or message carried by the packet.
	*/

	Packet(const std::string& src, const std::string& dest, const std::string& data);
};