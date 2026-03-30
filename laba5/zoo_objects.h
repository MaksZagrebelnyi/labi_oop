#ifndef ZOO_OBJECTS_H
#define ZOO_OBJECTS_H

#include "idescribable.h"
#include <string>
using namespace std;

class ZooAnimalCard : public IDescribable {
private:
    string animalName;
    string species;
    string habitat;
public:
    ZooAnimalCard(string n, string s, string h)
        : animalName(n), species(s), habitat(h) {}

    void printLabel() const override {
        cout << "Animal Card | Name: " << animalName
             << ", Species: " << species
             << ", Habitat: " << habitat << endl;
    }

    string getType() const override {
        return "ZooAnimalCard";
    }

    bool isPublic() const override {
        return true;
    }
};

class ZooEntrance : public IDescribable {
private:
    string sectionName;
    int    capacity;
    bool   restricted;
public:
    ZooEntrance(string n, int cap, bool r = false)
        : sectionName(n), capacity(cap), restricted(r) {}

    void printLabel() const override {
        cout << "Zoo Section | Name: " << sectionName
             << ", Capacity: " << capacity
             << ", Access: " << (restricted ? "RESTRICTED" : "OPEN") << endl;
    }

    string getType() const override {
        return "ZooEntrance";
    }

    bool isPublic() const override {
        return !restricted;
    }
};

#endif
