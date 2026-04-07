#include "Hotel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>



void Hotel::addRoom(int number, string type, double price, bool taken)
{
    Room room(number, type, price, taken);
    rooms.push_back(room);
}
void Hotel::addCustomer(string name, string checkin, string checkout, int number)
{
    Customer customer(name, checkin, checkout, number);
    customers.push_back(customer);
}
list<Room> Hotel::getRooms() { return rooms; }


void Hotel::initializeSystem(const string& filename1, const string& filename2) {
    ifstream in(filename1);
    if (!in) {
        cout << "Error opening file: " << filename1 << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        int roomNumber;
        string type;
        double price;
        bool taken;

        ss >> roomNumber >> type >> price >> taken;

        addRoom(roomNumber, type, price, taken);
    }
    in.close();

    in.open(filename2);
    if (!in) {
        cout << "Error opening file: " << filename2 << endl;
        return;
    }

    while (getline(in, line)) {
        stringstream ss(line);
        string name, checkin, checkout;
        int roomNumber;

        ss >> name >> checkin >> checkout >> roomNumber;
        addCustomer(name, checkin, checkout, roomNumber);
    }

    in.close();
}

void Hotel::displayHotelDescription() {
    cout << "Hotel Description:\n" << endl;
    cout << "Number of Rooms: " << rooms.size() << endl;

    // Display each room's details
    cout << "Rooms:" << endl;
    for (const Room& r : rooms) {
        cout << "Room number: " << r.roomNumber << "\n Room type: " << r.type << "\n Price per night: $" << r.price;
        if (r.isAvailable) {
            cout << "\n Status: Available\n" << endl;
        }
        else {
            cout << "\n Status: Booked\n" << endl;
        }
    }

}

void Hotel::checkInCustomer(const string& name, const string& checkIn, const string& checkOut, int number) {
    bool roomFound = false;
    bool roomAvailable = false;

    // Search for the room and update its availability
    for (Room& r : rooms)
    {
        if (r.roomNumber == number)
        {
            roomFound = true;
            if (r.isAvailable)
            {
                r.isAvailable = false;
                roomAvailable = true;
            }
            break;
        }
    }

    if (!roomFound)
    {
        cout << "Room number " << number << " does not exist." << endl;
        return;
    }

    if (!roomAvailable)
    {
        cout << "Room number " << number << " is not available." << endl;
        return;
    }

    // Add the customer to the customers list
    addCustomer(name, checkIn, checkOut, number);

    cout << "\nCustomer " << name << " checked in successfully from " << checkIn << " to " << checkOut << endl;

}
void Hotel::checkOutCustomer(int number) {
    auto it = customers.begin();
    for (; it != customers.end(); ++it) {
        if (it->roomNumber == number) {
            break;
        }
    }

    if (it == customers.end()) {
        cout << "No customer found for room number " << number << "." << endl;
        return;
    }
    Customer checkedOutCustomer = *it;
    customers.erase(it);
    bool roomFound = false;
    for (Room& r : rooms) {
        if (r.roomNumber == number) {
            r.isAvailable = true;
            roomFound = true;
            break;
        }
    }

    if (!roomFound) {
        cout << "Room number " << number << " does not exist." << endl;
        return;
    }

    cout << "Customer " << checkedOutCustomer.name << " checked out from room number " << number << " successfully." << endl;
}


void Hotel::viewAvailableRooms() {
    cout << "Available rooms: \n" << endl;

    list<Room> rooms = this->getRooms();
    for (const Room& r : rooms)
    {
        if (r.isAvailable == true)
        {
            cout << "Room number: " << r.roomNumber << " \n Room Type: " << r.type << " \n Price per night:" << r.price << "\n" << endl;
        }
    }
}

void Hotel::viewBookedRooms() {
    cout << "Unavailable rooms: \n" << endl;


    list<Room> rooms = this->getRooms();

    for (const Room& r : rooms) {
        if (!r.isAvailable) {
            cout << "Room number: " << r.roomNumber << "\n Room Type: " << r.type << "\n Price per night: $" << r.price;

            bool customerFound = false;
            for (const Customer& customer : customers) {
                if (customer.roomNumber == r.roomNumber) {
                    cout << "\n Customer Name: " << customer.name;
                    customerFound = true;
                    break;
                }
            }

            if (!customerFound) {
                cout << "\n No customer assigned";
            }

            cout << endl;
        }
    }
}


void Hotel::viewBillingSystem() {
    std::cout << "Billing System:" << std::endl;
    std::cout << std::left << std::setw(20) << "Customer Name" << std::setw(15) << "Room Number" << std::setw(15) << "Days Stayed" << std::setw(15) << "Total Cost" << std::endl;

    for (Customer& customer : customers) {
        int daysStayed = customer.calculateDaysStayed();
        double roomPrice = 0.0;
        for (const Room& room : rooms) {
            if (room.roomNumber == customer.roomNumber) {
                roomPrice = room.price;
                break;
            }
        }
        double totalCost = daysStayed * roomPrice;

        std::cout << std::left << std::setw(20) << customer.name << std::setw(15) << customer.roomNumber << std::setw(15) << daysStayed << "$" << std::fixed << std::setprecision(2) << totalCost << std::endl;
    }
}

void Hotel::saveCurrentState(const string& filename1, const string& filename2) {
    ofstream out(filename1);

    if (!out)
    {
        cout << "Error opening file: " << filename1 << endl;
    }

    for (const Room& r : rooms)
    {
        out << r.roomNumber << " " << r.type << " " << r.price << " " << r.isAvailable << "\n";
    }

    out.close();

    ofstream out2(filename2);

    if (!out2)
    {
        cout << "Error opening file: " << filename2 << endl;
    }

    for (const Customer& c : customers)
    {
        out2 << c.name << " " << c.checkInDate << " " << c.checkOutDate << " " << c.roomNumber << "\n";
    }

    out2.close();
};

