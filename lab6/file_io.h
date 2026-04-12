#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <sstream>
#include "zoo_storage.h"

inline void saveAnimals(ZooStorage& storage) {
    ofstream file("animals.dat");
    if (!file.is_open()) {
        cout << "Error: cannot open animals.dat for writing" << endl;
        return;
    }
    file << storage.ticketPrice << "\n";
    for (auto& a : storage.animals) {
        bool isPred = (dynamic_cast<Predator*>(a.get()) != nullptr);
        file << a->name << "," << a->type << "," << a->age << ","
             << a->weight << "," << a->gender << "," << isPred << "\n";
    }
    file.close();
}

inline void loadAnimals(ZooStorage& storage) {
    ifstream file("animals.dat");
    if (!file.is_open()) return;

    string line;
    if (getline(file, line) && !line.empty()) {
        try { storage.ticketPrice = stoi(line); } catch (...) {}
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, type, ageStr, weightStr, gender, predStr;
        try {
            getline(ss, name,      ',');
            getline(ss, type,      ',');
            getline(ss, ageStr,    ',');
            getline(ss, weightStr, ',');
            getline(ss, gender,    ',');
            getline(ss, predStr,   ',');

            int age    = stoi(ageStr);
            int weight = stoi(weightStr);
            bool isPred = (predStr == "1");

            if (isPred)
                storage.addAnimal(make_shared<Predator>(type, name, age, weight, gender));
            else
                storage.addAnimal(make_shared<Animal>(type, name, age, weight, gender));
        } catch (...) {
            cout << "Warning: skipped malformed line in animals.dat" << endl;
        }
    }
    file.close();
}

inline void saveHistory(ZooStorage& storage) {
    ofstream file("history.log");
    if (!file.is_open()) {
        cout << "Error: cannot open history.log for writing" << endl;
        return;
    }
    for (auto& h : storage.history)
        file << h << "\n";
    file.close();
}

inline void loadHistory(ZooStorage& storage) {
    ifstream file("history.log");
    if (!file.is_open()) return;
    string line;
    while (getline(file, line))
        if (!line.empty()) storage.history.push_back(line);
    file.close();
}

inline string loadPassword() {
    ifstream file("admin.cfg");
    if (!file.is_open()) return "2008";
    string pwd;
    getline(file, pwd);
    return pwd.empty() ? "2008" : pwd;
}

inline void savePassword(const string& pwd) {
    ofstream file("admin.cfg");
    if (!file.is_open()) {
        cout << "Error: cannot open admin.cfg for writing" << endl;
        return;
    }
    file << pwd << "\n";
    file.close();
}

#endif
