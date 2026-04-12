#include <iostream>
#include "zoo_storage.h"
#include "file_io.h"
#include "menu.h"

using namespace std;

int main() {
    try {
        ZooStorage storage;
        loadAnimals(storage);
        loadHistory(storage);

        Menu menu(storage);
        menu.run();

    } catch (exception& e) {
        cout << "Fatal error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
