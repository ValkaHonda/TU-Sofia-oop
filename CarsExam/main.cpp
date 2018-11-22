#include <iostream>
#include <sstream>
using namespace std;

/*Даден е базов абстрактен клас Auto, който съдържа полетата:
-> тип на автомобила(лек, товарен)
-> марка символен низ
-> година на производство
Инициализиращ конструктор с параметри.
Реализирайте абстрактен метод за извеждане на съдържанието на обекта в символен низ.
Даден е производен клас на клас Auto -> лек автомобил -> Car с полета, наследени от Auto,
и максимална скорост. Демонстрирайте работата на класовете със създаване на колекция от различни типове автомобили
и извеждане на информация за всички леки автомобили, които са произведени през 2000 година.*/
class Auto{
    protected: string type;
             string brand;
             int year;
    public:
        Auto(string, string, int);
        virtual ~Auto(){
        cout << "Parent class destructor." << endl;
        };
        virtual string printData() = 0;
        string getType() {return type;}
        int getYear() {return year;}

};
Auto::Auto(string type, string brand, int year){
this->type = type; this->brand = brand; this->year = year;
}

class Car:public Auto{
private: double maxSpeed;
public:
    Car(string, string, int, double);
    ~Car(){
    cout << "Child destructor." << endl;
    };
    string printData();

};
Car::Car(string type, string brand, int year, double maxSpeed):Auto(type, brand, year){
this->maxSpeed = maxSpeed;
}
string Car::printData() {
stringstream sstm;
sstm << brand << " " << type << endl;
string result = sstm.str();
return result;
}

int main()
{
    cout << "Hello world!" << endl;

    Auto* cars[3];
    Auto* car1 = new Car("Car", "Honda", 1997, 200);
    Auto* car2 = new Car("Car", "Suzuki", 2000, 210);
    Auto* car3 = new Car("Car", "Ford", 2004, 230);

    cars[0] = car1;
    cars[1] = car2;
    cars[2] = car3;
    for(int i = 0; i < 3; i++) {
        if(cars[i]->getType() == "Car" && cars[i]->getYear() == 2000)
        {cout<< "Data: " <<cars[i]->printData() << endl;}
                                }

    delete car1;
    delete car2;
    delete car3;





    return 0;
}
