#include <iostream>

using namespace std;

class Animal {
private:
    string name;
    int legsCount;
public:
    Animal ();
    Animal (string, int);
    void setName(string);
    string getName();
    void setLegsCount(int);
    int getLegsCount();
};
Animal::Animal()
{
    this->setName("Default name");
    this->setLegsCount(3);
}
Animal::Animal(string name, int legsCount)
{
    this->setName(name);
    this->setLegsCount(legsCount);
}
void Animal::setName(string name)
{
    this->name = name;
}
string Animal::getName()
{
    return name;
}
void Animal::setLegsCount(int legsCount)
{
    this->legsCount = legsCount;
}
int Animal::getLegsCount()
{
    return legsCount;
}
int main()
{
    Animal defaultAnimal;
    defaultAnimal.setName("Lucky");
    Animal dog("Bucky", 4);
    cout << defaultAnimal.getName() << "   " << defaultAnimal.getLegsCount() << endl;
    cout << dog.getName() << "   " << dog.getLegsCount() << endl;





    return 0;
}
