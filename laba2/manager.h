//
// Created by maks2 on 02.03.2026.
//
#include <iostream>
#include <string>

using namespace std;
#ifndef UNTITLED2_MENEGER_H
#define UNTITLED2_MENEGER_H

#endif //UNTITLED2_MENEGER_H

class Meneger {
private:
    int age;
    string namee;
public:

    Meneger(int a = 3, string n = "Anton") : age(a), namee(n) {}

    void prrint() {
        cout << "name=" << namee << ", age=" << age << "\n";
    }
};