#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Optic{
private:
    string opticType;
    string thickness;
    string material;
    double diopter;
    double price;
public:
    Optic();
    Optic(string,string,string,double ,double);
    void showData();
    double getPrice();
};
Optic::Optic(){}
Optic::Optic(string opticType,string thickness,string material,double diopter,double price){
        this->opticType = opticType;
        this->thickness = thickness;
        this->material = material;
        this->diopter = diopter;
        this->price = price;
}
void Optic::showData(){
        cout << '\t' << "Optic type: " << opticType << endl;
        cout << '\t' << "thickness: " << thickness<< endl;
        cout << '\t' << "material: " << material << endl;
        cout << '\t' << "diopter: " << diopter << endl;
        cout << '\t' << "price: " << price << endl;
    }
double Optic::getPrice(){
    return price;
}

class OpticFactory{
private:
public:
    Optic CreateOptic();
};

Optic OpticFactory::CreateOptic(){
        string opticType;
        cout << "Enter the type of Optic" << endl;
        cin >> opticType;

        string thickness;
        cout << "Enter the thickness of Optic" << endl;
        cin >> thickness;

        string material;
        cout << "Enter the material of Optic" << endl;
        cin >> material;

        double diopter;
        cout << "Enter the diopter of Optic" << endl;
        cin >> diopter;

        double price;
        cout << "Enter the price of Optic" << endl;
        cin >> price;
        Optic optic(opticType,thickness,material,diopter,price);
        return optic;
    }

class Provider{
private:
    string bulstat;
    string fName;
    string lName;
    string phone;
    string address;
    vector<Optic> optics;
public:
    Provider();
    Provider(string,string,string ,string ,string);
    void showOptics();
    void showData();
    void addOptic(Optic newOptic);
    vector<Optic> getOptics();
};

Provider::Provider(){ }
Provider::Provider(string bulstat,string fName,string lName,string phone,string address){
    this->bulstat = bulstat;
    this->fName = fName;
    this->lName = lName;
    this->phone = phone;
    this->address = address;
}
void Provider::showOptics(){
    for(unsigned int i = 0; i < optics.size(); i++){
        cout << i << "." << endl;
        optics[i].showData();
        cout << endl;
    }
}
void Provider::showData(){
    cout << "First name: " << this->fName << endl;
    cout << "Last name: " << this->lName << endl;
    cout << "Optics:" << endl;
    showOptics();
}
void Provider::addOptic(Optic newOptic){
    this->optics.push_back(newOptic);
}
vector<Optic> Provider::getOptics(){
    return optics;
}

class ProviderFactory{
private:
public:
    Provider createProvider();
};
Provider ProviderFactory::createProvider(){
    string bulstat;
    cout << "Enter bulstat" << endl;
    cin >> bulstat;

    string fName;
    cout << "Enter first name" << endl;
    cin >> fName;

    string lName;
    cout << "Enter last name" << endl;
    cin >> lName;

    string phone;
    cout << "Enter phone" << endl;
    cin >> phone;

    string address;
    cout << "Enter address" << endl;
    cin >> address;
    Provider provider(bulstat,fName,lName,phone,address);
    return provider;
}
class FileIO{
private:
    string path;
public:
    FileIO();
    void saveProviders();
    vector<Provider> loadProviders();
};
int main()
{
    cout << "Welcome!" << endl;
    cout << "Thank you for using us" << endl;
    return 0;
}
