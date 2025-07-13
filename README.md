# SDNSim 🛰️ - Software Defined Network Simulator (C++)

A minimal C++ simulation of a Software Defined Network (SDN), featuring a centralized controller that manages network devices and their connections.

This is an educational and expandable simulation project built with C++ and Visual Studio, designed to model basic SDN behavior like device management, neighbor relationships, and controller logic.

---

## 💡 Features

- ✅ Central `Controller` that manages all devices  
- ✅ `Device` class with neighbor tracking  
- ✅ Connection logic using unordered maps  
- ✅ Simple command-line test output  
- 🚧 More advanced features planned (see below)  

---

## 📁 Project Structure

- `Controller.cpp` / `.h` — Manages all devices and their connections  
- `Device.cpp` / `.h` — Represents a single network node  
- `SDNSim.cpp` — Entry point for simulation  
- `SDNSim.sln` — Visual Studio solution  

---

## 🧪 Sample Output

- Router neighbors: Switch
- Switch neighbors: Router Firewall
- Firewall neighbors: Switch


---

## 🚀 Planned Features

- Fault detection and rerouting  
- Latency simulation  
- Visual representation or logs  
- AI-driven decision logic for the controller  

---

## 🎯 Goals

This project is designed as a learning tool to explore:

- Data structures like `unordered_map`  
- Object-oriented modeling in C++  
- Network topologies and SDN logic  
- Expandability toward AI and simulation research  
