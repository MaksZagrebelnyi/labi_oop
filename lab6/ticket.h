#ifndef TICKET_H
#define TICKET_H

#include <iostream>
using namespace std;

class Ticket {
private:
    int price;
public:
    Ticket(int p = 100) : price(p) {
        cout << "Ticket constructor was called" << endl;
    }
    Ticket(const Ticket& other) : price(other.price) {
        cout << "Ticket copy constructor was called" << endl;
    }
    Ticket& operator=(const Ticket& rhs) {
        cout << "Ticket operator= was called" << endl;
        if (this != &rhs) price = rhs.price;
        return *this;
    }
    void setPrice(int p) { price = p; }
    void showPrice() const { cout << "Ticket price: " << price << endl; }
    ~Ticket() { cout << "Ticket destructor was called" << endl; }
};

#endif
