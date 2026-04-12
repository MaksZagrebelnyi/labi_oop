#ifndef IDESCRIBABLE_H
#define IDESCRIBABLE_H

#include <iostream>
using namespace std;

class IDescribable {
public:
    virtual void printLabel() const = 0;
    virtual string getType() const = 0;
    virtual bool isPublic() const = 0;
    virtual ~IDescribable() {}
};

void printInfo(const IDescribable& obj) {
    cout << "Type: " << obj.getType()
         << " | Public: " << (obj.isPublic() ? "yes" : "no") << endl;
    obj.printLabel();
}

#endif
