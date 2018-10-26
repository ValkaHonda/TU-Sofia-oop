#include <iostream>

using namespace std;

class Number {
private:
    int number;
    int* arr;
public:
    Number* number2;
    Number();
    Number(int);
    int getNumber();
    int getSecondIndexElement();
    Number(const Number &other){
        this->arr = other.arr;
        this->number = other.number;
        this->number2 = other.number2;
    }
    ~Number();
};

Number::Number(){
    cout << "default" << endl;
}

Number::Number(int number){
    this->number = number;
    this->arr = new int[5];
    this->arr[2] = 100;
    this->number2 = new Number(7);
}

int Number::getNumber(){
    return number;
}

int Number::getSecondIndexElement(){
    return arr[2];
}
Number::~Number(){
    cout << "Calling destructor" << endl;
    delete arr;
    delete number2;
}

void printObjectNumberState(Number number){
    cout << "The number is: " << number.getNumber() << endl;
    cout << "The number at index 2 is: " << number.getSecondIndexElement() << endl;
    //cout << "Number 2 is: " << number.number2->getNumber() << endl;
}

Number createNumber(){
    Number num(18);
    return num;
}


int main()
{
    cout << "Hello world!" << endl;
    Number obj(8);
    cout << obj.getNumber();
    printObjectNumberState(obj);
    Number obj2 = createNumber();
    printObjectNumberState(obj2);
    return 0;
}
