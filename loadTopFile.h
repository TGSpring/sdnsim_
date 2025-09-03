#pragma once

#include <string>
#include "Controller.h"

/**
 * @brief Loads a topology from a file and prints neighbor info.
 *
 * @param control Reference to the Controller object managing devices.
 * @param filename Path to the topology file.
 */
void loadAndPrintTopology(Controller& control, const std::string& filename);

