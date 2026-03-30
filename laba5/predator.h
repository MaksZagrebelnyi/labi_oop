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

    string getCategory() const override {
        return "Predator";
    }

    void describe() const override {
        cout << "Predator: " << name << " is a dangerous " << type
             << ", weight: " << weight << "kg. Beware!" << endl;
    }

    virtual ~Predator() {
        cout << "Predator destructor was called" << endl;
    }
};

class WildPredator final : public Predator {
public:
    WildPredator(string t = "WildPredator", string n = "UnknownWild",
                 int a = 0, int w = 0, string g = "Unknown")
        : Predator(t, n, a, w, g) {
        cout << "WildPredator constructor was called" << endl;
    }

    void showInfo() const override {
        cout << "WildPredator: " << name
             << ", type: "   << type
             << ", weight: " << weight << "kg [WILD]" << endl;
    }

    void describe() const override {
        cout << "WildPredator: " << name
             << " - extremely dangerous wild animal!" << endl;
    }

    ~WildPredator() {
        cout << "WildPredator destructor was called" << endl;
    }
};

#endif

