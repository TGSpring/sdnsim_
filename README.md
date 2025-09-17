# SDNSim 🛰️ - Software Defined Network Simulator (C++)

SDNSim is a C++ simulation of a Software Defined Network (SDN), featuring a centralized controller that manages network devices, connections, packet routing, and network clearing. This is an **educational and expandable project** built with Visual Studio to model core SDN behavior.

---

## 💡 Features (Phase 1 Complete)

- ✅ Central `Controller` that manages all devices  
- ✅ `Device` class with neighbor tracking  
- ✅ Add/remove devices and bidirectional connections  
- ✅ Device active/inactive status  
- ✅ Connection logic using unordered maps  
- ✅ Topology loading from file (`topology.txt`)  
  - Supports comments, blank lines, self-loops, and duplicate connections  
- ✅ Packet sending simulation with logs for success/failure  
- ✅ Network reset via `clearAllDevices()`  
- ✅ Fully documented with Doxygen  

---

## 📁 Project Structure

- `Controller.cpp` / `.h` — Manages all devices and network logic  
- `Device.cpp` / `.h` — Represents a single network device  
- `Packet.cpp` / `.h` — Represents a network packet (future use)  
- `loadTopFile.cpp` / `.h` — Handles topology file loading and printing  
- `SDNSim.cpp` — Entry point for simulation  
- `SDNSim.sln` — Visual Studio solution  

---

## 🧪 Sample Output

[INFO] Topology loaded from topology.txt
--- Devices Loaded ---
Router
DownLink
Firewall
Switch

--- Device Neighbors ---
Router neighbors: Switch DownLink Firewall
DownLink neighbors: Router
Firewall neighbors: Router
Switch neighbors: Router

--- Packet Tests (Loaded Topology) ---
Controller attempting to send packet...
Router is active. Preparing to send packet...
Switch is active. Packet destination valid.
Packet from Router to Switch: Ping
Controller attempting to send packet...
Router is active. Preparing to send packet...
Firewall is currently inactive.
Packet from Router to Firewall: Ping
Controller attempting to send packet...
Router is active. Preparing to send packet...
DownLink is currently inactive.
Packet from Router to DownLink: Ping

[INFO] All devices cleared from the network.
All devices cleared successfully.
Router not found after clearing, as expected.


---

## 🚀 Roadmap & Planned Features

### Phase 1 – Core Simulation (Complete)

- Device management, neighbor tracking, and active/inactive status  
- Packet sending simulation with verification of existence, activity, and neighbor relationship  
- Topology loading from file with comments, blank lines, duplicate/self-loop handling  
- Network clearing via `clearAllDevices()`  
- Command-line tests and Doxygen documentation  

### Phase 2 – GUI & Interaction (Upcoming)

- Interactive GUI to add/remove devices  
- Visual display of network topology  
- Device status toggling and packet testing through GUI  
- Console log integration and optional packet flow animation  
- Optimizations like `const std::string&` for performance  

### Phase 3 – Fault Detection & Network Simulation (Upcoming)

- Random device or link failures  
- Rerouting logic for packets if direct links fail  
- Packet statistics and logging (sent/received, success/failure)  

### Phase 4 – Advanced Features (Optional / Future)

- AI/ML-driven routing and adaptive device state management  
- Web-based simulation (WASM)  
- Extended topologies with multiple controllers and VLAN/subnets  
- Plugin system for custom device types and packet rules  

---

## 🎯 Learning Goals

- C++ data structures (`unordered_map`, `vector`)  
- Object-oriented modeling (`Controller`, `Device`, `Packet`)  
- File parsing and topology management  
- Simulation of SDN logic, packet routing, and network resets  
- Expandability toward GUI, AI, and advanced network simulation
