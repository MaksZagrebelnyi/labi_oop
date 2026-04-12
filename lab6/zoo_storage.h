#ifndef ZOO_STORAGE_H
#define ZOO_STORAGE_H

#include <vector>
#include <memory>
#include "animal.h"
#include "predator.h"

class ZooStorage {
public:
    vector<shared_ptr<Animal>> animals;
    vector<string> history;
    int ticketPrice = 100;

    void addAnimal(shared_ptr<Animal> a) {
        animals.push_back(a);
    }

    void removeAnimal(int index) {
        if (index >= 0 && index < (int)animals.size())
            animals.erase(animals.begin() + index);
    }

    void log(const string& msg) {
        history.push_back(msg);
    }
};

#endif
