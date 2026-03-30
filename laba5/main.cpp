#include <iostream>
#include <utility>
#include "Visitor.h"
#include "Manager.h"
#include "Animal.h"
#include "Predator.h"
#include "Ticket.h"
#include "Zoo.h"
#include "ResourceBox.h"

using namespace std;

int main() {
    cout << "Visitor:" << endl;
    Visitor lisa("Lisa", 17);
    lisa.goToZoo();
    lisa.sayHello();
    lisa.showInfo();

    Animal lion("Lion", "Aleksey", 5, 120, "male");
    Animal copyLion = lion;
    copyLion.showInfo();

    Animal tiger("Tiger", "Sherhan", 6, 200, "male");
    tiger = lion;
    tiger.showInfo();

    Predator wolf("Wolf", "Yarik", 4, 80, "male");
    wolf.hunt();
    wolf.showInfo();

    Manager manager1("Anton", 35, 2000);
    Manager manager2("Oleg", 40, 2500);
    Manager manager3 = manager1;
    manager2 = manager1;
    manager1.showInfo();
    manager2.showInfo();
    manager3.showInfo();
    cout << "Managers amount: " << Manager::getAmountOfManagers() << endl;

    Ticket ticket(150);
    Zoo zoo1("Dari", "Ukraine", manager1, lion, ticket);
    zoo1.showZoo();

    ResourceBox box1(500);
    ResourceBox box2 = std::move(box1);
    box1.showData();
    box2.showData();

    return 0;
}