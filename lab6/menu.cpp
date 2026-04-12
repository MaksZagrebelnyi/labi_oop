#include "menu.h"

void Menu::adminMenu() {
    cout << "\n=== ADMIN PANEL ===" << endl;
    int choice;
    do {
        cout << "\n1. View animals\n2. Add animal\n3. Add predator\n"
             << "4. Remove animal\n5. Set ticket price\n6. View history\n0. Logout\n"
             << "Choice: ";
        choice = getInt("");

        if (choice == 1) {
            if (storage.animals.empty()) {
                cout << "No animals in the zoo." << endl;
            } else {
                for (int i = 0; i < (int)storage.animals.size(); i++) {
                    cout << i + 1 << ". ";
                    storage.animals[i]->showInfo();
                }
            }

        } else if (choice == 2 || choice == 3) {
            string name   = getStr("Name: ");
            string type   = getStr("Type: ");
            int    age    = getInt("Age: ");
            int    weight = getInt("Weight (kg): ");
            string gender = getStr("Gender: ");

            try {
                if (choice == 3)
                    storage.addAnimal(make_shared<Predator>(type, name, age, weight, gender));
                else
                    storage.addAnimal(make_shared<Animal>(type, name, age, weight, gender));
                saveAnimals(storage);
                cout << "Added successfully." << endl;
            } catch (exception& e) {
                cout << "Error: " << e.what() << endl;
            }

        } else if (choice == 4) {
            if (storage.animals.empty()) {
                cout << "No animals to remove." << endl;
            } else {
                for (int i = 0; i < (int)storage.animals.size(); i++) {
                    cout << i + 1 << ". " << storage.animals[i]->name << endl;
                }
                int idx = getInt("Number to remove: ") - 1;
                if (idx >= 0 && idx < (int)storage.animals.size()) {
                    cout << storage.animals[idx]->name << " removed." << endl;
                    storage.removeAnimal(idx);
                    saveAnimals(storage);
                } else {
                    cout << "Invalid number." << endl;
                }
            }

        } else if (choice == 5) {
            cout << "Current price: " << storage.ticketPrice << " UAH" << endl;
            int p = getInt("New price: ");
            if (p < 0) {
                cout << "Price cannot be negative." << endl;
            } else {
                storage.ticketPrice = p;
                saveAnimals(storage);
                cout << "Price updated." << endl;
            }

        } else if (choice == 6) {
            if (storage.history.empty()) {
                cout << "History is empty." << endl;
            } else {
                for (auto& h : storage.history) cout << h << endl;
            }
        }

    } while (choice != 0);
}

void Menu::visitorMenu() {
    string name = getStr("\nEnter your name: ");
    if (name.empty()) name = "Visitor";
    cout << "Welcome, " << name << "!" << endl;

    int choice;
    do {
        cout << "\n1. View animals\n2. Buy ticket\n3. View history\n0. Exit\nChoice: ";
        choice = getInt("");

        if (choice == 1) {
            if (storage.animals.empty()) {
                cout << "No animals in the zoo yet." << endl;
            } else {
                for (int i = 0; i < (int)storage.animals.size(); i++) {
                    cout << i + 1 << ". ";
                    storage.animals[i]->describe();
                }
            }

        } else if (choice == 2) {
            cout << "Ticket price: " << storage.ticketPrice << " UAH" << endl;
            cout << "Buy? (1 = yes, 0 = no): ";
            int confirm = getInt("");
            if (confirm == 1) {
                Ticket t(storage.ticketPrice);
                t.showPrice();
                string entry = name + " bought a ticket for " + to_string(storage.ticketPrice) + " UAH";
                storage.log(entry);
                saveHistory(storage);
                cout << "Enjoy the zoo!" << endl;
            }

        } else if (choice == 3) {
            bool found = false;
            for (auto& h : storage.history) {
                if (h.find(name + " ") == 0) {
                    cout << h << endl;
                    found = true;
                }
            }
            if (!found) cout << "No history for " << name << "." << endl;
        }

    } while (choice != 0);
    cout << "Goodbye, " << name << "!" << endl;
}

void Menu::run() {
    cout << "\n=== ZOO MANAGEMENT SYSTEM ===" << endl;
    int choice;
    do {
        cout << "\n1. Admin\n2. Visitor\n0. Exit\nChoice: ";
        choice = getInt("");

        if (choice == 1) {
            string pass = getStr("Password: ");
            if (pass == adminPassword) {
                cout << "Login successful!" << endl;
                adminMenu();
            } else {
                cout << "Wrong password." << endl;
            }
        } else if (choice == 2) {
            visitorMenu();
        }

    } while (choice != 0);
    cout << "Goodbye!" << endl;
}
