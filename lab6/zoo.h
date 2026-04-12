#ifndef ZOO_H
#define ZOO_H

#include "manager.h"
#include "animal.h"
#include "ticket.h"

class Zoo {
private:
    string  name;
    string  place;
    Manager manager;
    Animal  animal;
    Ticket  ticket;
public:
    Zoo(string n = "UnknownZoo", string p = "UnknownPlace",
        const Manager& m = Manager(), const Animal& a = Animal(),
        const Ticket& t = Ticket())
        : name(n), place(p), manager(m), animal(a), ticket(t) {
        cout << "Zoo constructor was called" << endl;
    }
    Zoo(string n, string p) : Zoo(n, p, Manager(), Animal(), Ticket()) {}
    Zoo(string n) : Zoo(n, "UnknownPlace", Manager(), Animal(), Ticket()) {}
    Zoo() : Zoo("UnknownZoo", "UnknownPlace", Manager(), Animal(), Ticket()) {}

    void showZoo() const {
        cout << "Zoo: " << name << ", place: " << place << endl;
        manager.showInfo();
        animal.showInfo();
        ticket.showPrice();
    }
    ~Zoo() { cout << "Zoo destructor was called" << endl; }
};

#endif
