#include <iostream>
#include <string>
#include "HUMANS.h"
#include "ANIMALS.h"
#include "MENEGER.h"
#include "ZOOPARKI.h"

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
