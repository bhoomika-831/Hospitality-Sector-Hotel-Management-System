#pragma once
#define HOTEL_H

#include "Room.h"
#include "Customer.h"
#include <list>
#include <string>

using namespace std;

class Hotel {
private:
    list<Room> rooms;
    list<Customer> customers;
public:
    void addRoom(int number, string type, double price, bool taken);
    void addCustomer(string name, string checkin, string checkout, int number);
    list<Room> getRooms();

    void initializeSystem(const string& filename1, const string& filename2);
    void displayHotelDescription();
    void checkInCustomer(const string& name, const string& checkIn, const string& checkOut, int roomNumber);
    void checkOutCustomer(int roomNumber);
    void viewAvailableRooms();
    void viewBookedRooms();
    void viewBillingSystem();
    void saveCurrentState(const string& filename1, const string& filename2);
};


