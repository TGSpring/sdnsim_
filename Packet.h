#pragma once
#include <string>

class Packet {
public:
	std::string source;
	std::string destination;
	std::string payload;

	Packet(const std::string& src, const std::string& dest, const std::string& data);
};