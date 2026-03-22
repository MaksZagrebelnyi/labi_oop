#ifndef ANIMAL_H
#define ANIMAL_H

#include "LivingBeing.h"

class Animal : public LivingBeing {
protected:
    string type;
    int weight;
    string gender;

public:
    Animal(string t = "UnknownType", string n = "UnknownAnimal", int a = 0, int w = 0, string g = "Unknown") : LivingBeing(n, a), type(t), weight(w), gender(g) {
        cout << "Animal constructor was called" << endl;
    }
    Animal(string n) : Animal("UnknownType", n, 0, 0, "Unknown") {}
    Animal(string n, int w) : Animal("UnknownType", n, 0, w, "Unknown") {}
    Animal(string t, string n, int w) : Animal(t, n, 0, w, "Unknown") {}
    Animal(const Animal& other)
        : LivingBeing(other), type(other.type), weight(other.weight), gender(other.gender) {
        cout << "Animal copy constructor was called" << endl;
    }

    Animal& operator=(const Animal& rhs) {
        cout << "Animal operator= was called" << endl;

        if (this != &rhs) {
            LivingBeing::operator=(rhs);
            type = rhs.type;
            weight = rhs.weight;
            gender = rhs.gender;
        }

        return *this;
    }

    void setWeight(int w) {
        this->weight = w;
    }

    void setGender(string g) {
        this->gender = g;
    }

    void makeSound() const {
        cout << name << " makes a sound" << endl;
    }

    void showInfo() const override {
        cout << "Animal: " << name
             << ", type: " << type
             << ", age: " << age
             << ", weight: " << weight
             << ", gender: " << gender << endl;
    }

    ~Animal() {
        cout << "Animal destructor was called" << endl;
    }
};

#endif