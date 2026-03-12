#ifndef UNTITLED2_HUMANS_H
#define UNTITLED2_HUMANS_H

#include <iostream>
#include <string>

using namespace std;

class Human {
public:
    string name;
    int age;

    Human(string n = "UnknownHuman", int a = 0) : name(n), age(a) {}

    void setInfo(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void goToZoo() const {
        cout << name << " go to Zoo" << endl;
    }

    void showInfo() const {
        cout << "Human: " << name << ", age = " << age << endl;
    }

    bool compareObjects(const Human& other) const {
        if (this == &other) {
            cout << "Objects are equal" << endl;
            return true;
        }
        cout << "Objects are different" << endl;
        return false;
    }
};

class Visitor : public Human {
public:
    Visitor(string n = "UnknownVisitor", int a = 0) : Human(n, a) {}
    Visitor(string n) : Visitor(n, 0) {}
    Visitor() : Visitor("UnknownVisitor", 0) {}

    void sayHello() const {
        cout << name << " say: hello" << endl;
    }

    ~Visitor() {}
};

#endif