#include <iostream>
#include <string.h>

using namespace std;

/*
Създайте клас животно със следните член променливи:
-> име (указател към символен низ/char*)
-> година
направете копиращ конструктор
*/
class Animal{
private:
    char* name;
    int year;
public:
   Animal(char*, int);
   ///Animal(const Animal &);
    Animal(){}
    ~Animal();
    void printName();
};
void Animal::printName(){
    for(int i = 0; i < 3; i++){
        cout<<name[i];
    }
    cout<<endl;
}

Animal::~Animal(){
    cout<<"The memory is freed"<<endl;
    delete []name;
}

Animal::Animal(char* name, int year){
    ///Step 1:
    int nameSize = strlen(name);
    ///Step 2:
    this -> name = new char[nameSize + 1];
    ///Step 3:
    strcpy(this -> name, name);
    this -> year = year;
}
int main()
{
    char* p = new char[20];
    p[0] = 'A';
    p[1] = 'B';
    p[2] = 'C';
    p[3] = '/0';


    Animal dog(p,10);
    dog.printName();
    p[1] = 'H';
    dog.printName();



    delete []p;
    return 0;
}
