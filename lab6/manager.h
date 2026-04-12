#ifndef MANAGER_H
#define MANAGER_H

#include "worker.h"

class Manager : public Worker {
private:
    static int amountOfManagers;

public:
    Manager(string n = "Anton", int a = 30, int s = 1000)
        : Worker(n, a, s) {
        amountOfManagers++;
        cout << "Manager constructor was called" << endl;
    }

    Manager(const Manager& other) : Worker(other) {
        amountOfManagers++;
        cout << "Manager copy constructor was called" << endl;
    }

    Manager& operator=(const Manager& rhs) {
        cout << "Manager operator= was called" << endl;
        if (this != &rhs) {
            Worker::operator=(rhs);
        }
        return *this;
    }

    static int getAmountOfManagers() {
        return amountOfManagers;
    }

    void showInfo() const override {
        cout << "Manager: " << name << ", age: " << age
             << ", salary: " << salary << endl;
    }

    string getCategory() const override {
        return "Manager";
    }

    void describe() const override {
        cout << "Manager: " << name << ", age: " << age
             << ", salary: $" << salary << " - manages the zoo" << endl;
    }

    virtual ~Manager() {
        amountOfManagers--;
        cout << "Manager destructor was called" << endl;
    }
};

#endif
