#include <iostream>
#include <utility>
#include "HUMAN.h"
#include "ANIMAL.h"
#include "Manager.h"
#include "ZOO.h"

using namespace std;

int main() {
    Visitor Lisa("Lisa", 17);
    Lisa.stInfo("Lisa", 17);


    Lisa.showInfo();
    Lisa.compareObjects(Lisa);

    const Visitor constVisitor("Max", 18);
    constVisitor.showInfo();
    constVisitor.sayHello();
    constVisitor.goToZoo();

    cout << "\n try copy constructor " << endl;
    Animal Leshaa("Lion", "Aleksey", 120, "male");
    Animal copyAnimal = Leshaa;
    cout << copyAnimal << endl;

    cout << "\ntry move constructor" << endl;
    Zoo Dari("Dari", "Ukraine", 123, 20000);
    Zoo movedZoo = move(Dari);
    movedZoo.openZoo();
    movedZoo.showPrice();

    cout << "\n try static " << endl;
    Manager manager1;
    Manager manager2(25, "Oleg");
    manager1.printInfo();
    manager2.printInfo();
    cout << "Amount of managers = " << Manager::getAmountOfManagers() << endl;

    cout << "\ntry unary and binary operators" << endl;
    ++movedZoo;
    movedZoo.showPrice();

    Zoo expensiveZoo = movedZoo + 50;
    expensiveZoo.showPrice();

    Animal inputAnimal;
    cout << "Enter: type name weight gender" << endl;
    cin >> inputAnimal;
    cout << inputAnimal << endl;

    return 0;
}