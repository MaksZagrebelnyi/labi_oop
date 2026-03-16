#ifndef UNTITLED2_ZOO_H
#define UNTITLED2_ZOO_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Zoo {
private:
    int square;
    int price;

public:
    string place;
    string name;

    Zoo(string name = "Unknown", string place = "Ukraine", int price = 10, int square = 20000)
        : square(square), price(price), place(place), name(name) {}

    Zoo(Zoo&& other) : square(other.square), price(other.price), place(move(other.place)), name(move(other.name)) {
        cout << "Move constructor was called" << endl;
        other.square = 0;
        other.price = 0;
        other.place = "moved_from";
        other.name = "moved_from";
    }

    void showPrice() const {
        cout << price << " - ticket price" << endl;
    }

    void setPrice(int price) {
        this->price = price;
        cout << "price = " << price << endl;
    }

    void closeZoo() const {
        cout << "zoo " << name << " close" << endl;
    }

    void openZoo() const {
        cout << name << " open" << endl;
    }

    Zoo& operator++() {
        ++price;
        return *this;
    }

    Zoo operator+(int value) const {
        Zoo temp(name, place, price + value, square);
        return temp;
    }

    ~Zoo() {}
};

#endif