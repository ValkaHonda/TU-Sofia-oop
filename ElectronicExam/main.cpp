#include <iostream>
#include <vector>
using namespace std;
class ElectronicComponents
 {
  private: int ID; string type; int value; string measure_unit;
  public:
  ElectronicComponents();
  ElectronicComponents(int, string, int, string);
 ~ElectronicComponents();
    void displayData();
    string getType();
    int getValue();

 };
class SpecificComponent: public ElectronicComponents
{
 private: string country; double price;
 public:
 SpecificComponent();
 SpecificComponent(int, string, int, string, string, double);
 ~SpecificComponent();
   void displaySpecificData();
};

ElectronicComponents::ElectronicComponents() {};
ElectronicComponents::ElectronicComponents(int ID, string type, int value, string measure_unit)
{this->ID = ID; this->type = type; this->value = value; this->measure_unit = measure_unit;}
ElectronicComponents::~ElectronicComponents() {cout << "The object is destroyed." << endl;}
void ElectronicComponents::displayData() {cout << "ID: " << this->ID << endl; cout << "Type: " << this->type << endl;}
SpecificComponent::SpecificComponent() {cout << "The object is constructed." << endl;}
SpecificComponent::SpecificComponent(int ID, string type, int value, string measure_unit, string country, double price):ElectronicComponents(ID, type, value, measure_unit)
{this->country = country; this->price = price;}
SpecificComponent::~SpecificComponent() {cout << "The object is destroyed" << endl;}
void SpecificComponent::displaySpecificData() {this->displayData();
                                               cout << "Country: " <<this->country << endl;
                                               cout << "Price: " <<this->price << endl;}
string ElectronicComponents::getType() {return type;}
int ElectronicComponents::getValue() {return value;}


int main()
{
 SpecificComponent firstComponent(1, "resistance", 7, "kiloOhm", "Russia", 0.5);
 SpecificComponent secondComponent(2, "capacitor", 100, "mF", "Belgium", 1);
 SpecificComponent thirdComponent(3, "transistor", 0, "p", "Bulgaria", 1.2);
 SpecificComponent fourthComponent(4, "capacitor", 1, "p", "Japan", 5);

 vector<SpecificComponent> components;
 components.push_back(firstComponent);
 components.push_back(secondComponent);
 components.push_back(thirdComponent);
 components.push_back(fourthComponent);
 components.erase(components.begin()+1);
 for(unsigned int i = 0; i < components.size(); i++)
 {
  if(components[i].getType() == "capacitor" && components[i].getValue() >= 1 && components[i].getValue() <= 2)
  {components[i].displaySpecificData();}
 }



return 0;
}
