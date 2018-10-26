#include <iostream>
using namespace std;
//Building classes & methods:
class Auto {
private: string type, brand; int year;
public: Auto();
        Auto(string, string, int);
virtual void printCarDetails()=0;
string getType();
string getBrand();
int getYear();
};
Auto::Auto() {
this->type = "Normal car";
this->year = 1997;
};
Auto::Auto(string type, string brand, int year) {
this->type = type;
this->brand= brand;
this->year = year;
}
string Auto::getType() {
return type;
}
string Auto::getBrand() {
return brand;
}
int Auto::getYear() {
return year;
}

class Car: public Auto  {//Class#1:Class#2 - Inheritance //:: - implementation of methods
private: int max_speed;
public:
    int getMaxSpeed();
    void printCarDetails();
    Car();
    Car(string, string, int, int);
};
Car::getMaxSpeed() {
    return max_speed;
}
Car::Car():Auto(){max_speed = 0;}
Car::Car(string type, string brand, int year, int max_speed):Auto(type, brand, year){
this->max_speed = max_speed;
}
void Car::printCarDetails() {
    cout << "Type: " << this->getType() << endl;
    cout << "Brand: " << this->getBrand() << endl;
    cout << "Year: " << this->getYear() << endl;
    cout << "Max Speed: " << this->getMaxSpeed() << endl;
}
int main() {
cout << "Hello!" << endl;
Car car;
car.printCarDetails();
cout << "Polymorphism Example" << endl;
Auto* car_1 = new Car("Truck", "Mercedes", 1980, 140);
Auto* car_2 = new Car("Normal car", "BMW", 2000, 200);
Auto* car_3 = new Car("Normal car", "Audi", 2003, 220);
Auto* cars[3];
cars[0] = car_1;
cars[1] = car_2;
cars[2] = car_3;
for(int i = 0; i<3; i++) {
if(cars[i]->getType() == "Normal car" && cars[i]->getYear()<2000)
            {cars[i]->printCarDetails();}
        else {cout <<cars[i]->getBrand()<<" The car doesn't match the requirements!" << endl;}




cout << "Stack Object Example" << endl;
cout << endl;
Car firstCar("Normal car", "Audi", 2001, 220);
Car secondCar("Truck", "Mercedes", 1999, 140);
Car stackCarsArray[2];
stackCarsArray[0] = firstCar;
stackCarsArray[1] = secondCar;
for (int i = 0; i<2; i++) {
stackCarsArray[i].printCarDetails();

}
}
return 0;
};
