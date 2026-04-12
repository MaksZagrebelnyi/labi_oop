#ifndef HUMAN_H
#define HUMAN_H

#include "livingbeing.h"

class Human : public LivingBeing {
public:
    Human(string n = "UnknownHuman", int a = 0) : LivingBeing(n, a) {
        cout << "Human constructor was called" << endl;
    }

    Human(const Human& other) : LivingBeing(other) {
        cout << "Human copy constructor was called" << endl;
    }

    Human& operator=(const Human& rhs) {
        cout << "Human operator= was called" << endl;
        if (this != &rhs) {
            LivingBeing::operator=(rhs);
        }
        return *this;
    }

    void goToZoo() const {
        cout << name << " goes to the zoo" << endl;
    }

    void showInfo() const override {
        cout << "Human: " << name << ", age: " << age << endl;
    }

    string getCategory() const override {
        return "Human";
    }

    void describe() const override {
        cout << "Human: " << name << ", age: " << age << endl;
    }

    virtual ~Human() {
        cout << "Human destructor was called" << endl;
    }
};

#endif
