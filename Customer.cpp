#include "Customer.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

Customer::Customer(string name, string checkIn, string checkOut, int roomNumber) : name(name), checkInDate(checkIn), checkOutDate(checkOut), roomNumber(roomNumber) {}
int Customer::calculateDaysStayed() {
    struct tm checkIn = {};
    struct tm checkOut = {};

    istringstream ssCheckIn(checkInDate);
    istringstream ssCheckOut(checkOutDate);

    ssCheckIn >> std::get_time(&checkIn, "%Y-%m-%d");
    ssCheckOut >> std::get_time(&checkOut, "%Y-%m-%d");

    time_t checkInTime = mktime(&checkIn);
    time_t checkOutTime = mktime(&checkOut);

    double difference = difftime(checkOutTime, checkInTime);
    int daysStayed = difference / (60 * 60 * 24);

    return daysStayed;
}
