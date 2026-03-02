//
// Created by maks2 on 02.03.2026.
//
#include <iostream>
#include <string>

using namespace std;
#ifndef UNTITLED2_HUMANS_H
#define UNTITLED2_HUMANS_H

#endif //UNTITLED2_HUMANS_H

class Humans {
public:
    string name;
    int age;
    Humans(string n = "UnknownHuman", int a = 0) : name(n), age(a) {}

    void goo() {
        cout << name << "goo to Zoopark" << endl;
    }
};

class Visitors : public Humans {
public:
    void heloo() {
        cout << name << " say: hello" << endl;
    }

    Visitors(string n = "UnknownVisitor", int a = 0) : Humans(n, a) {}
    Visitors(string n) : Visitors(n, 0) {}
    Visitors() : Visitors("UnknownVisitor", 0) {}

    ~Visitors() {}
};