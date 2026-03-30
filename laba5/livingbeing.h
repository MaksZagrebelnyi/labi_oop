#ifndef LIVING_BEING_H
#define LIVING_BEING_H

#include <iostream>
#include <string>

using namespace std;

class LivingBeing {
public:
    string name;
    int age;

    LivingBeing(string n = "Unknown", int a = 0) : name(n), age(a) {
        cout << "LivingBeing constructor was called" << endl;
    }

    LivingBeing(const LivingBeing& other) : name(other.name), age(other.age) {
        cout << "LivingBeing copy constructor was called" << endl;
    }

    LivingBeing& operator=(const LivingBeing& rhs) {
        cout << "LivingBeing operator= was called" << endl;
        if (this != &rhs) {
            name = rhs.name;
            age  = rhs.age;
        }
        return *this;
    }

    void setData(string name, int age) {
        this->name = name;
        this->age  = age;
    }

    virtual void showInfo() const {
        cout << "Name: " << name << ", age: " << age << endl;
    }

    virtual string getCategory() const {
        return "LivingBeing";
    }

    virtual void describe() const = 0;

    virtual ~LivingBeing() {
        cout << "LivingBeing destructor was called" << endl;
    }
};

#endif
