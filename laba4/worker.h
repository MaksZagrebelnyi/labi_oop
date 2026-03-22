#ifndef WORKER_H
#define WORKER_H

#include "Human.h"

class Worker : public Human {
protected:
    int salary;

public:
    Worker(string n = "UnknownWorker", int a = 0, int s = 0)
        : Human(n, a), salary(s) {
        cout << "Worker constructor was called" << endl;
    }

    Worker(const Worker& other) : Human(other), salary(other.salary) {
        cout << "Worker copy constructor was called" << endl;
    }

    Worker& operator=(const Worker& rhs) {
        cout << "Worker operator= was called" << endl;

        if (this != &rhs) {
            Human::operator=(rhs);
            salary = rhs.salary;
        }

        return *this;
    }

    void showInfo() const override {
        cout << "Worker: " << name << ", age: " << age
             << ", salary: " << salary << endl;
    }

    virtual ~Worker() {
        cout << "Worker destructor was called" << endl;
    }
};

#endif