#ifndef MENU_H
#define MENU_H

#include "zoo_storage.h"
#include "file_io.h"
#include "ticket.h"
#include <limits>

class Menu {
private:
    ZooStorage& storage;
    string adminPassword;

    int getInt(const string& prompt) {
        int val;
        cout << prompt;
        while (!(cin >> val)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. " << prompt;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return val;
    }

    string getStr(const string& prompt) {
        string s;
        cout << prompt;
        getline(cin, s);
        return s;
    }

    void adminMenu();
    void visitorMenu();

public:
    Menu(ZooStorage& s) : storage(s) {
        adminPassword = loadPassword();
    }

    void run();
};

#endif
