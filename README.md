# SDNSim 🛰️ - Software Defined Network Simulator (C++)

A minimal C++ simulation of a Software Defined Network (SDN), featuring a centralized controller that manages network devices and their connections.

This is an **educational and expandable simulation project** built with C++ and Visual Studio, designed to model basic SDN behavior like device management, neighbor relationships, and controller logic.

---

## 💡 Features (Phase 1 Complete)

- ✅ Central `Controller` that manages all devices  
- ✅ `Device` class with neighbor tracking  
- ✅ Add/remove devices and bidirectional connections  
- ✅ Device active/inactive status  
- ✅ Connection logic using unordered maps  
- ✅ Topology loading from file (`topology.txt`)  
- ✅ Simple command-line test output for packet routing  
- ✅ Doxygen documentation generated for all classes and methods  

---

## 📁 Project Structure

- `Controller.cpp` / `.h` — Manages all devices and their connections  
- `Device.cpp` / `.h` — Represents a single network node  
- `Packet.cpp` / `.h` — Represents a network packet  
- `loadTopFile.cpp` / `.h` — Handles topology file loading and printing  
- `SDNSim.cpp` — Entry point for simulation  
- `SDNSim.sln` — Visual Studio solution  

---

## 🧪 Sample Output

--- Devices Loaded ---
Router
Switch
Firewall
DownLink

--- Device Neighbors ---
Router neighbors: Switch Firewall DownLink
Switch neighbors: Router
Firewall neighbors: Router
DownLink neighbors: Router

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


---

## 🚀 Roadmap & Planned Features

### **Phase 1 – Core Simulation (Complete)**

- Device management, neighbor tracking, and active/inactive status  
- Packet sending simulation with verification of existence, activity, and neighbor relationship  
- Topology loading from file with comments, blank lines, duplicate/self-loop handling  
- Command-line tests and Doxygen documentation  

### **Phase 2 – GUI & Interaction (Upcoming)**

- Interactive GUI to add/remove devices  
- Visual display of network topology  
- Device status toggling and packet testing through the GUI  
- Console log integration and optional packet flow animation  

### **Phase 3 – Fault Detection & Network Simulation (Upcoming)**

- Random device or link failures  
- Rerouting logic for packets if direct links fail  
- Packet statistics and logging (sent/received, success/failure)  

### **Phase 4 – Advanced Features (Optional / Future)**

- AI/ML-driven routing and adaptive device state management  
- Web-based simulation (WASM)  
- Extended topologies with multiple controllers and VLAN/subnets  
- Plugin system for custom device types and packet rules  

---

## 🎯 Learning Goals

This project is designed as a **hands-on learning tool** for:

- C++ data structures (`unordered_map`, `vector`)  
- Object-oriented modeling (`Controller`, `Device`, `Packet`)  
- File parsing and topology management  
- Simulation of SDN logic and basic packet routing  
- Expandability toward AI, GUI, and advanced network simulation  
