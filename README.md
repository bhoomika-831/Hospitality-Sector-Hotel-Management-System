# Hotel Management System
### Hospitality Sector — C++ Console Application

> **Language:** C++ &nbsp;|&nbsp; **Type:** Console Application &nbsp;|&nbsp; **IDE:** Visual Studio

---

## Overview

The Hotel Management System is a C++ object-oriented console application that simulates core hotel front-desk operations. It enables staff to manage room inventory, register guests, process check-outs, and generate billing summaries — all through an interactive menu-driven interface with persistent file-based storage.

---

## Features

| Feature | Description |
|---|---|
| System Initialize | Loads room and customer data from flat text files to restore saved hotel state |
| Hotel Overview | Displays all rooms with room number, type, price per night, and availability status |
| Check-In | Registers a guest with name, validated dates (YYYY-MM-DD), and room number; marks room as occupied |
| Check-Out | Releases a room and removes the customer record from the active list |
| Available Rooms | Lists all currently bookable rooms with type and nightly rate |
| Booked Rooms | Displays all occupied rooms alongside the assigned guest name |
| Billing System | Calculates and displays days stayed and total cost per guest based on room rate |
| Save State | Persists current rooms and customer data back to file for future sessions |

---

## Project Structure

```
HotelManagementSystem/
│
├── Project.cpp                  # Entry point — main menu loop and input handling
├── Hotel.h / Hotel.cpp          # Core class — manages room/customer lists and all business logic
├── Room.h / Room.cpp            # Room model — stores number, type, price, and availability
├── Customer.h / Customer.cpp    # Customer model — stores guest details, calculates days stayed
│
├── Room.txt                     # Persistent storage for room data
├── Customer.txt                 # Persistent storage for active guest data
│
├── Project.sln                  # Visual Studio solution file
├── Project.vcxproj              # Visual Studio project file
└── Project.vcxproj.filters      # Visual Studio filters
```

---

## How to Run

### Prerequisites
- Visual Studio 2019 or later (Windows)
- C++17 or later standard enabled
- `Room.txt` and `Customer.txt` present in the project directory

### Steps
```
1. Open Project.sln in Visual Studio
2. Build the solution        (Ctrl + Shift + B)
3. Run the project           (F5 or Ctrl + F5)
4. Select option 1 "Initialize System" on first launch
```

---

## Menu Options

```
┌─────────────────────────────────────────┐
│         HOTEL MANAGEMENT SYSTEM         │
├─────────────────────────────────────────┤
│  1.  Initialize System                  │
│  2.  Display Hotel Description          │
│  3.  Check-in Customer                  │
│  4.  Check-out Customer                 │
│  5.  View Available Rooms               │
│  6.  View Booked Rooms                  │
│  7.  View Billing System                │
│  8.  Save Current State                 │
│  0.  Exit                               │
└─────────────────────────────────────────┘
```

---

## Input Format

Dates must be entered in the following format:
```
YYYY-MM-DD    (e.g. 2025-06-15)
```
The system validates date input automatically and will prompt again if the format is incorrect.

---

## Data File Format

### Room.txt
```
<roomNumber> <type> <price> <isAvailable>

101 Single 99.99 1
102 Double 149.99 0
```

### Customer.txt
```
<name> <checkInDate> <checkOutDate> <roomNumber>

JohnDoe 2025-06-01 2025-06-05 102
```

---

## OOP Design

```
Hotel
 ├── list<Room>       — room inventory
 └── list<Customer>   — active guests

Room
 ├── roomNumber
 ├── type
 ├── price
 └── isAvailable

Customer
 ├── name
 ├── checkInDate
 ├── checkOutDate
 ├── roomNumber
 └── calculateDaysStayed()
```

---

*Built with C++ — Hospitality Sector | Hotel Management System*
