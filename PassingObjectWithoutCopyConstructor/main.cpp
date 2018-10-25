#include <iostream>

using namespace std;

class Number {
private:
    int number;
    int* arr;
public:
    Number(int);
    int getNumber();
    int getSecondIndexElement();
};

Number::Number(int number){
    this->number = number;
    this->arr = new int[5];
    this->arr[2] = 100;
}

int Number::getNumber(){
    return number;
}

int Number::getSecondIndexElement(){
    return arr[2];
}

void printObjectNumberState(Number number){
    cout << "The number is: " << number.getNumber() << endl;
    cout << "The number is: " << number.getSecondIndexElement() << endl;
}

Number createNumber(){
    Number num(18);
    return num;
}

int main()
{
    cout << "Hello world!" << endl;
    Number obj(8);
    printObjectNumberState(obj);
    Number obj2 = createNumber();
    printObjectNumberState(obj2);
    return 0;
}
