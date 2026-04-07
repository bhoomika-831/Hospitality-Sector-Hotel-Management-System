#pragma once
#define CUSTOMER_H
#include <string>


using namespace std;

class Customer {
public:
    string name;
    string checkInDate;
    string checkOutDate;
    int roomNumber;

    Customer(string name, string checkIn, string checkOut, int roomNumber);

    int calculateDaysStayed() ;
};

