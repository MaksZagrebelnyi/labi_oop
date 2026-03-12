#ifndef UNTITLED2_MANAGER_H
#define UNTITLED2_MANAGER_H

#include <iostream>
#include <string>

using namespace std;

class Manager {
private:
    int age;
    string name;
    static int amountOfManagers;

public:
    Manager(int a = 3, string n = "Anton") : age(a), name(n) {
        amountOfManagers++;
    }

    void printInfo() const {
        cout << "name = " << name << ", age = " << age << endl;
    }

    static int getAmountOfManagers() {
        return amountOfManagers;
    }

    ~Manager() {
        amountOfManagers--;
    }
};

#endif