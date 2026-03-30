#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal {
public:
    Predator(string t = "Predator", string n = "UnknownPredator",
             int a = 0, int w = 0, string g = "Unknown")
        : Animal(t, n, a, w, g) {
        cout << "Predator constructor was called" << endl;
    }

    void hunt() const {
        cout << name << " is hunting" << endl;
    }

    void showInfo() const override {
        cout << "Predator: " << name
             << ", type: " << type
             << ", age: " << age
             << ", weight: " << weight
             << ", gender: " << gender << endl;
    }

    ~Predator() {
        cout << "Predator destructor was called" << endl;
    }
};

#endif