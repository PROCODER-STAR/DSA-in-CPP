#include <iostream>
#include <cstring>

using namespace std;

class Flight {
private:
    char* name;  
    int seatNo;

public:
	
    Flight(const char* passengerName, int seat) {
        name = new char[strlen(passengerName) + 1];
        strcpy(name, passengerName);
        seatNo = seat;
    }

    Flight(const Flight& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        seatNo = other.seatNo;
    }

    Flight& operator=(const Flight& other) {
        if (this != &other) { 
            delete[] name; 

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            seatNo = other.seatNo;
        }
        return *this;
    }

    ~Flight() {
        delete[] name;
    }

    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    void display() const {
        cout << "Passenger: " << name << ", Seat No: " << seatNo << endl;
    }
};

int main() {

    Flight booking1("Alice Johnson", 12);

    Flight booking2 = booking1;

    booking2.setName("Bob Smith");

    cout << "Original Booking:" << endl;
    booking1.display();

    cout << "Copied Booking (after modification):" << endl;
    booking2.display();

    return 0;
}
