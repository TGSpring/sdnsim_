#pragma once
#include <string>
#include <vector>
//Will be using std::string and vector for simplicity with naming "devices".

class Device {
private:
	std::string name;
	std::vector<std::string> neighbors;

public:
	//using const ref to avoid copying strings.
	//Using const and ref to prevent copying too many strings and prevent unwanted changes.
	Device(const std::string& deviceName);
	std::string getName() const;
	const std::vector<std::string>& getNeighbors() const;

	//Going to be used to modify neighbors.
	void addNeighbor(const std::string& neighborName);
};