#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
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
    string toFileLineString();
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
string Optic::toFileLineString(){
    std::stringstream ss;
    ss << opticType << endl;
    ss << thickness << endl;
    ss << material << endl;
    ss << diopter << endl;
    ss << price << endl;
    return ss.str();
}
double Optic::getPrice(){
    return price;
}

class OpticFactory{
public:
    OpticFactory();
    Optic createOptic();
};

OpticFactory::OpticFactory(){}

Optic OpticFactory::createOptic(){
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
    string toFileLineString();
};
string Provider::toFileLineString(){
    std::stringstream ss;
    ss << bulstat << endl;
    ss << fName << endl;
    ss << lName << endl;
    ss << phone << endl;
    ss << address << endl;

    ss << "-->" << endl;
    for(unsigned int i = 0; i < optics.size(); i++){
        ss << optics[i].toFileLineString();
    }
    ss << "<--" << endl;

    return ss.str();
}

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
    FileIO(string);
    void saveProviders(vector<Provider>);
    vector<Provider> loadProviders();
};
FileIO::FileIO(){}

FileIO::FileIO(string filePath){
    path = filePath;
}
void FileIO::saveProviders(vector<Provider> providers){
    ofstream outputStream;
    outputStream.open(path);
    for(unsigned int i = 0; i < providers.size(); i++){
        string strProvider = providers[i].toFileLineString();
        outputStream << strProvider;
    }
    outputStream << "TU-End" << endl;
    outputStream.close();
}

class AppController{
private:
    OpticFactory opticFactory;
    ProviderFactory providerFactory;
    FileIO file;
    vector<Provider> providers;
public:
    AppController(ProviderFactory, OpticFactory, FileIO);
    void addProvider();
    void addProvider(Provider);
    void saveToFile();
    void showProviders();
};


AppController::AppController(ProviderFactory p, OpticFactory o, FileIO f){
    this->providerFactory = p;
    this->opticFactory = o;
    this->file = f;
}

void AppController::addProvider(){
    Provider provider = providerFactory.createProvider();
    providers.push_back(provider);
}

void AppController::addProvider(Provider provider){
    providers.push_back(provider);
}
void AppController::showProviders(){
    for(unsigned int i = 0; i < providers.size(); i++){
        providers[i].showData();
    }
}
void AppController::saveToFile(){
    file.saveProviders(providers);
}
void showMenu(){
    cout << "0. Exit." << endl;
    cout << "1. Add Provider." << endl;
    cout << "2. Show providers." << endl;
    cout << "3. Save to File." << endl;
}
int main()
{
    cout << "Welcome!" << endl;

    // dummy data
    ProviderFactory providerFactory;
    OpticFactory opticFactory;
    FileIO file("omegaData.txt");

    AppController app(providerFactory,opticFactory, file);

    Provider p1("bulstat1","fName1","lName1","phone1","address1");
    Provider p2("bulstat2","fName2","lName2","phone2","address2");
    Provider p3("bulstat3","fName3","lName3","phone3","address3");

    Optic o1("pticType","thickness","material",0.5,10);
    Optic o2("pticType2","thickness2","material2",1,20);
    Optic o3("pticType3","thickness3","material3",2,30);
    Optic o4("pticType4","thickness4","material4",3,40);
    Optic o5("pticType5","thickness5","material5",4,50);

    p1.addOptic(o1);
    p1.addOptic(o2);
    p1.addOptic(o5);
    p3.addOptic(o3);
    p2.addOptic(o4);

    app.addProvider(p1);
    app.addProvider(p2);
    app.addProvider(p3);


    //testting save to file

    int choise = -1;
    showMenu();
    cin >> choise;
    while(choise > 0){
        if(choise == 1){
            cout << "--> Add Provider" << endl;
            cout << endl;
            app.addProvider();
        } else if(choise == 2){
            cout << "--> Display" << endl;
            cout << endl;
            app.showProviders();
        } else if(choise == 3){
            cout << "--> Save to File" << endl;
            cout << endl;
            app.saveToFile();
            cout << "Save complete" << endl;
        }else {
            break;
        }
        showMenu();
        cin >> choise;
    }

    cout << "Thank you for using us" << endl;
    return 0;
}
