#ifndef VISITOR_H
#define VISITOR_H

#include "Human.h"

class Visitor : public Human {
public:
    Visitor(string n = "UnknownVisitor", int a = 0) : Human(n, a) {
        cout << "Visitor constructor was called" << endl;
    }
    Visitor(string n) : Visitor(n, 0) {}
    Visitor() : Visitor("UnknownVisitor", 0) {}

    void sayHello() const {
        cout << name << " says hello" << endl;
    }

    void showInfo() const override {
        cout << "Visitor: " << name << ", age: " << age << endl;
    }

    ~Visitor() {
        cout << "Visitor destructor was called" << endl;
    }
};

#endif