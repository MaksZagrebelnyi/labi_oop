#ifndef UNTITLED2_ANIMALS_H
#define UNTITLED2_ANIMALS_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string gender;
    int weight;

public:
    string type;
    string name;

    Animal(string type = "UnknownType", string name = "UnknownAnimal", int weight = 0, string gender = "Unknown")
        : gender(gender), weight(weight), type(type), name(name) {}

    Animal(string name) : Animal("UnknownType", name, 0, "Unknown") {}
    Animal(string name, int weight) : Animal("UnknownType", name, weight, "Unknown") {}
    Animal(string type, string name, int weight) : Animal(type, name, weight, "Unknown") {}

    Animal(const Animal& other)
        : gender(other.gender), weight(other.weight), type(other.type), name(other.name) {
        cout << "Copy constructor was called" << endl;
    }

    void showWeight() const {
        cout << "Weight = " << weight << endl;
    }

    void setWeight(int weight) {
        this->weight = weight;
        cout << type << " " << name << " weight now = " << weight << endl;
    }

    void setGender(string gender) {
        this->gender = gender;
    }

    void makeSound() const {
        cout << "say_smt " << name << endl;
    }

    friend ostream& operator<<(ostream& out, const Animal& a) {
        out << "Animal -> type: " << a.type
            << ", name: " << a.name
            << ", weight: " << a.weight
            << ", gender: " << a.gender;
        return out;
    }

    friend istream& operator>>(istream& in, Animal& a) {
        in >> a.type >> a.name >> a.weight >> a.gender;
        return in;
    }

    ~Animal() {}
};

#endif