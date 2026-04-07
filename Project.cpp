#include "Hotel.h"
#include <iostream>
#include <limits>
#include <string>
#include <regex>
#include <exception>

using namespace std;

void displayMenu() {
    cout << "\n";
    cout << "1. Initialize System" << endl;
    cout << "2. Display Hotel Description" << endl;
    cout << "3. Check-in Customer" << endl;
    cout << "4. Check-out Customer" << endl;
    cout << "5. View Available Rooms" << endl;
    cout << "6. View Booked Rooms" << endl;
    cout << "7. View Billing System" << endl;
    cout << "8. Save Current State" << endl;
    cout << "0. Exit" << endl;
    cout << "\n";
}

string getValidatedDate(const string& prompt) {
    string date;
    regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    while (true) {
        cout << prompt;
        cin >> date;
        if (regex_match(date, datePattern)) {
            break;
        }
        else {
            cout << "Invalid date format. Please use YYYY-MM-DD." << endl;
        }
    }
    return date;
}

int main() {
    Hotel hotel;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        try {
            if (!(cin >> choice)) {
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            switch (choice) {
            case 1:
                hotel.initializeSystem("Room.txt", "Customer.txt");
                cout << "\nSystem Initialized\n";
                break;

            case 2:
                cout << "\n";
                hotel.displayHotelDescription();
                break;

            case 3: {
                string name, checkIn, checkOut;
                int roomNumber;
                cout << "\n";
                cout << "Enter customer name: ";
                cin >> name;
                checkIn = getValidatedDate("Enter check-in date (YYYY-MM-DD): ");
                checkOut = getValidatedDate("Enter check-out date (YYYY-MM-DD): ");

                cout << "Enter room number: ";
                if (!(cin >> roomNumber)) {
                    throw invalid_argument("Invalid input for room number. Please enter a number.");
                }

                hotel.checkInCustomer(name, checkIn, checkOut, roomNumber);
                break;
            }

            case 4: {
                int roomNumber;
                cout << "\n";
                cout << "Enter room number: ";
                if (!(cin >> roomNumber)) {
                    throw invalid_argument("Invalid input for room number. Please enter a number.");
                }
                hotel.checkOutCustomer(roomNumber);
                break;
            }

            case 5:
                cout << "\n";
                hotel.viewAvailableRooms();
                break;

            case 6:
                cout << "\n";
                hotel.viewBookedRooms();
                break;

            case 7:
                cout << "\n";
                hotel.viewBillingSystem();
                break;

            case 8:
                cout << "\n";
                hotel.saveCurrentState("Room.txt", "Customer.txt");
                break;

            case 0:
                cout << "\n";
                cout << "Exiting..." << endl;
                return 0;

            default:
                throw out_of_range("Invalid choice. Please try again.");
            }
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
