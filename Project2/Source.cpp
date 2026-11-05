#include <iostream>
#include <windows.h>

class Base {
public:
    virtual void myname() {
        std::cout << "This is class Base\n";
    }
    virtual ~Base() = default;
};

class DerA : virtual public Base {
public:
    void myname() override {
        std::cout << "This is class DerA\n";
    }
};

class DerB : virtual public Base {
public:
    void myname() override {
        std::cout << "This is class DerB\n";
    }
};

class DerAB : public DerA, public DerB {
public:
    void myname() override {
        std::cout << "This is class DerAB\n";
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Base b;
    DerA da;
    DerB db;
    DerAB dab;

    b.myname();
    da.myname();
    db.myname();
    dab.myname();

    std::cout << "\n";

    Base* arr[4];
    arr[0] = new Base();
    arr[1] = new DerA();
    arr[2] = new DerB();
    arr[3] = new DerAB();

    for (int i = 0; i < 4; ++i) {
        arr[i]->myname();
    }

    for (int i = 0; i < 4; ++i) {
        delete arr[i];
    }

    return 0;
}в