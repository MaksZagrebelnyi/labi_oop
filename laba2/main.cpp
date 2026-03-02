#include <iostream>
#include <string>
using namespace std;

// TEMA ZOOPARK

class ZOOPARKI {
private:
    int price;
    int square;

public:
    string place;
    string name;

    void wha_is_price_and_square(int price, int square) {
        this->price = price;
        this->square = square;
        cout << "price = " << price << " and square = " << square << endl;
    }

    void close_zoopark() {
        cout << "zoopark " << this->name << " close" << endl;
    }

    void open_zoopark() {
        cout << this->name << " open" << endl;
    }


    ZOOPARKI(string name, string place) : price(0), square(0), place(place), name(name) {}
    ZOOPARKI(string name) : ZOOPARKI(name, "Ukraine") {}
    ZOOPARKI() : ZOOPARKI("Unknown", "Ukraine") {}
    ~ZOOPARKI() {}
};

class Meneger {
public:
    int age;
    string namee;
    Meneger(int a = 3, string n = "Anton") : age(a), namee(n) {}

    void prrint() {
        cout << "name=" << namee << ", age=" << age << "\n";
    }
};

class Animals {
private:
    string gender;

public:
    string type;
    string name;
    int weight;

    void wha_is_gender(string gender) {
        this->gender = gender;
        cout << name << " gender = " << gender << endl;
    }

    void say_animal() {
        cout << "say_smt " << name << endl;
    }


    Animals(string type = "UnknownType", string name = "UnknownAnimal", int weight = 0, string gender = "Unknown")
        : gender(gender), type(type), name(name), weight(weight) {}


    Animals(string name) : Animals("UnknownType", name, 0, "Unknown") {}
    Animals(string name, int amount) : Animals("UnknownType", name, amount, "Unknown") {}
    Animals(string type, string name, int amount) : Animals(type, name, amount, "Unknown") {}

    ~Animals() {}
};

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

int main() {
    ZOOPARKI Dari("Dari", "Ukraine");
    Animals Leshaa("Lev" , "Aleksey");
    Visitors Lisa("Lisa", 17);
    Meneger cool;

    int price, square;
    cout << "Please enter price and square for open Zoopark Dari" << endl;
    cin >> price >> square;

    if (price < 0 || square < 0) {
        cout << "Please enter price and square for open Zoopark Dari" << endl;
        cin >> price >> square;
    }

    Dari.wha_is_price_and_square(price, square);
    Dari.open_zoopark();

    Lisa.goo();

    Leshaa.wha_is_gender("Male");
    Leshaa.say_animal();

    Lisa.heloo();

    cool.prrint();
    return 0;
}