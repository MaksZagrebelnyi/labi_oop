//
// Created by maks2 on 02.03.2026.
//
#include <iostream>
#include <string>

using namespace std;
#ifndef UNTITLED2_ANIMALS_H
#define UNTITLED2_ANIMALS_H

#endif //UNTITLED2_ANIMALS_H
class Animals {
private:
    string gender;

public:
    string type;
    string name;
    int weight;

    void wha_is_gender(string gender) {
        this->gender = gender;
        cout << name << " gender = " << gender << endl;
    }

    void say_animal() {
        cout << "say_smt " << name << endl;
    }


    Animals(string type = "UnknownType", string name = "UnknownAnimal", int weight = 0, string gender = "Unknown")
        : gender(gender), type(type), name(name), weight(weight) {}

    Animals(string name) : Animals("UnknownType", name, 0, "Unknown") {}
    Animals(string name, int amount) : Animals("UnknownType", name, amount, "Unknown") {}
    Animals(string type, string name, int amount) : Animals(type, name, amount, "Unknown") {}

    ~Animals() {}
};
