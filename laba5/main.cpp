#include <iostream>
#include <utility>
#include "visitor.h"
#include "manager.h"
#include "animal.h"
#include "predator.h"
#include "ticket.h"
#include "zoo.h"
#include "resourcebox.h"
#include "zoo_objects.h"

using namespace std;

int main() {

    Animal staticAnimal("Lion", "Simba", 3, 180, "male");
    Predator staticPredator("Wolf", "Grey", 4, 80, "male");
    Animal* staticPtr = &staticPredator;
    staticPtr->showInfo();

    LivingBeing* beings[] = {
        new Animal("Lion",   "Simba",  3, 180, "male"),
        new Animal("Parrot", "Kesha",  2,   1, "male"),
        new Predator("Wolf", "Serhii", 4,  80, "male"),
        new Visitor("Lisa", 17),
        new Manager("Anton", 35, 2000)
    };

    for (auto* b : beings) b->showInfo();
    cout << endl;
    for (auto* b : beings) cout << b->name << " -> " << b->getCategory() << endl;
    cout << endl;
    for (auto* b : beings) b->describe();
    cout << endl;
    for (auto* b : beings) delete b;

    Predator wolf("Wolf", "Yarik", 4, 80, "male");
    wolf.hunt();

    WildPredator wildLion("Lion", "Mufasa", 6, 200, "male");
    wildLion.showInfo();
    wildLion.hunt();
    wildLion.describe();

    Animal lion("Lion", "Alex", 5, 180, "male");
    Predator bear("Bear", "Mishko", 7, 300, "male");
    Visitor visitor("Olena", 25);
    Manager manager("Dmytro", 40, 3000);

    LivingBeing& lionRef = lion;
    LivingBeing& bearRef = bear;
    LivingBeing& visitorRef = visitor;
    LivingBeing& managerRef = manager;

    lionRef.showInfo();
    lionRef.describe();
    bearRef.showInfo();
    bearRef.describe();
    visitorRef.showInfo();
    visitorRef.describe();
    managerRef.showInfo();
    managerRef.describe();

    LivingBeing* catPtr = new Animal("Cat", "Murzik", 2, 4, "female");
    catPtr->showInfo();
    catPtr->describe();
    delete catPtr;

    ZooAnimalCard lionCard("Simba", "African Lion", "Savannah");
    ZooAnimalCard parrotCard("Kesha", "Macaw Parrot", "Tropical Forest");
    ZooEntrance mainEntrance("Main Hall", 500, false);
    ZooEntrance  predatorZone("Predator Zone", 50, true);

    IDescribable* items[] = { &lionCard, &parrotCard, &mainEntrance, &predatorZone };
    for (auto* item : items) printInfo(*item);

    Visitor lisa("Lisa", 17);
    lisa.goToZoo();
    lisa.sayHello();
    lisa.showInfo();

    Animal lionOrig("Lion", "Aleksey", 5, 120, "male");
    Animal copyLion = lionOrig;
    copyLion.showInfo();

    Animal tiger("Tiger", "Sherhan", 6, 200, "male");
    tiger = lionOrig;
    tiger.showInfo();

    Predator wolfOrig("Wolf", "Yarik", 4, 80, "male");
    wolfOrig.hunt();
    wolfOrig.showInfo();

    Manager manager1("Anton", 35, 2000);
    Manager manager2("Oleg", 40, 2500);
    Manager manager3 = manager1;
    manager2 = manager1;
    manager1.showInfo();
    manager2.showInfo();
    manager3.showInfo();
    cout << "Managers amount: " << Manager::getAmountOfManagers() << endl;

    Ticket ticket(150);
    Zoo zoo1("Dari", "Ukraine", manager1, lionOrig, ticket);
    zoo1.showZoo();

    ResourceBox box1(500);
    ResourceBox box2 = std::move(box1);
    box1.showData();
    box2.showData();

    return 0;
}
