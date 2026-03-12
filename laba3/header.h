#include <iostream>
#include <string>

using namespace std;

// THEME ZOO

class Zoo {
private:
    int price;
    int square;

public:
    string place;
    string name;

    void setPriceAndSquare(int price, int square) {
        this->price = price;
        this->square = square;
        cout << "price = " << price << " and square = " << square << endl;
    }

    void closeZoo() {
        cout << "zoo " << this->name << " close" << endl;
    }

    void openZoo() {
        cout << this->name << " open" << endl;
    }

    Zoo(string name, string place) : price(0), square(0), place(place), name(name) {}
    Zoo(string name) : Zoo(name, "Ukraine") {}
    Zoo() : Zoo("Unknown", "Ukraine") {}
    ~Zoo() {}
};

class Manager {
private:
    int age;
    string namee;

public:
    Manager(int a = 3, string n = "Anton") : age(a), namee(n) {}

    void printInfo() {
        cout << "name = " << namee << ", age = " << age << "\n";
    }
};

class Animal {
private:
    string gender;

public:
    string type;
    string name;
    int weight;

    void setGender(string gender) {
        this->gender = gender;
        cout << name << " gender = " << gender << endl;
    }

    void makeSound() {
        cout << "say_smt " << name << endl;
    }

    Animal(string type = "UnknownType", string name = "UnknownAnimal", int weight = 0, string gender = "Unknown")
        : gender(gender), type(type), name(name), weight(weight) {}

    Animal(string name) : Animal("UnknownType", name, 0, "Unknown") {}
    Animal(string name, int amount) : Animal("UnknownType", name, amount, "Unknown") {}
    Animal(string type, string name, int amount) : Animal(type, name, amount, "Unknown") {}

    ~Animal() {}
};

class Human {
public:
    string name;
    int age;

    Human(string n = "UnknownHuman", int a = 0) : name(n), age(a) {}

    void goToZoo() {
        cout << name << " go to Zoo" << endl;
    }
};

class Visitor : public Human {
public:
    void sayHello() {
        cout << name << " say: hello" << endl;
    }

    Visitor(string n = "UnknownVisitor", int a = 0) : Human(n, a) {}
    Visitor(string n) : Visitor(n, 0) {}
    Visitor() : Visitor("UnknownVisitor", 0) {}

    ~Visitor() {}
};