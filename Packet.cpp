#include "Packet.h"

Packet::Packet(const std::string& src, const std::string& dest, const std::string& data)
	: source(src), destination(dest), payload(data) {}