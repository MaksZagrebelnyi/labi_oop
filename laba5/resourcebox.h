#ifndef RESOURCE_BOX_H
#define RESOURCE_BOX_H

#include <iostream>

using namespace std;

class ResourceBox {
private:
    int* data;

public:
    ResourceBox(int value = 0) {
        data = new int;
        *data = value;
        cout << "ResourceBox constructor was called" << endl;
    }

    ResourceBox(const ResourceBox& other) {
        data = new int;
        *data = *other.data;
        cout << "ResourceBox copy constructor was called" << endl;
    }

    ResourceBox(ResourceBox&& other) : data(other.data) {
        other.data = nullptr;
        cout << "ResourceBox move constructor was called" << endl;
    }

    ResourceBox& operator=(const ResourceBox& rhs) {
        cout << "ResourceBox operator= was called" << endl;

        if (this != &rhs) {
            delete data;
            data = new int;
            *data = *rhs.data;
        }

        return *this;
    }

    void showData() const {
        if (data != nullptr) {
            cout << "Data = " << *data << endl;
        } else {
            cout << "Data = nullptr" << endl;
        }
    }

    ~ResourceBox() {
        delete data;
        cout << "ResourceBox destructor was called" << endl;
    }
};

#endif