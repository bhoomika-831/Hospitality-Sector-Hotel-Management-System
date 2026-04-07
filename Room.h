#pragma once
#define ROOM_H

#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    double price;
    string type;
    bool isAvailable;

    Room(int number, string type, double price, bool isAvailable);
};



