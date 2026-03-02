//
// Created by maks2 on 02.03.2026.
//
#include <iostream>
#include <string>

using namespace std;
#ifndef UNTITLED2_ZOOPARKI_H
#define UNTITLED2_ZOOPARKI_H

#endif //UNTITLED2_ZOOPARKI_H

class ZOOPARKI {
private:
    int price;
    int square;

public:
    string place;
    string name;

    void wha_is_price_and_square(int price, int square) {
        this->price = price;
        this->square = square;
        cout << "price = " << price << " and square = " << square << endl;
    }

    void close_zoopark() {
        cout << "zoopark " << this->name << " close" << endl;
    }

    void open_zoopark() {
        cout << this->name << " open" << endl;
    }


    ZOOPARKI(string name, string place) : price(0), square(0), place(place), name(name) {}
    ZOOPARKI(string name) : ZOOPARKI(name, "Ukraine") {}
    ZOOPARKI() : ZOOPARKI("Unknown", "Ukraine") {}
    ~ZOOPARKI() {}
};