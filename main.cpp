#include <iostream>

using namespace std;

class Vehicle {
private:
    int range;
public:
    virtual void drive() = 0;
};

class Car : public Vehicle{
public:
    void drive(){
        cout << "This is Car class" << endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Vehicle* car = new Car();
    car->drive();
    return 0;
}
