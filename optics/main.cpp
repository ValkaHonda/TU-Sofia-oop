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
    Optic(string opticType,string thickness,string material,double diopter,double price){
        this->opticType = opticType;
        this->thickness = thickness;
        this->material = material;
        this->diopter = diopter;
        this->price = price;
    }
    void showData(){
        cout << '\t' << "Optic type: " << opticType << endl;
        cout << '\t' << "thickness: " << thickness<< endl;
        cout << '\t' << "material: " << material << endl;
        cout << '\t' << "diopter: " << diopter << endl;
        cout << '\t' << "price: " << price << endl;
    }
    double getPrice(){
        return price;
    }
};
class OpticFactory{
private:
public:
    OpticFactory(){ }
    Optic* CreateOptic(){
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
        return new Optic(opticType,thickness,material,diopter,price);
    }
};

class Provider{
private:
    string bulstat;
    string fName;
    string lName;
    string phone;
    string address;
    vector<Optic*> optics;
public:
    Provider(){
    }
    Provider(string bulstat,string fName,string lName,string phone,string address){
        this->bulstat = bulstat;
        this->fName = fName;
        this->lName = lName;
        this->phone = phone;
        this->address = address;
    }
    void showOptics(){
        for(unsigned int i = 0; i < optics.size(); i++){
            cout << i << "." << endl;
            optics[i]->showData();
            cout << endl;
        }
    }
    void showData(){
        cout << "First name: " << this->fName << endl;
        cout << "Last name: " << this->lName << endl;
        cout << "Optics:" << endl;
        showOptics();
    }
    void addOptic(Optic* newOptic){
        this->optics.push_back(newOptic);
    }
    vector<Optic*> getOptics(){
        return optics;
    }
};

class ProviderFactory{
private:
public:
    Provider* createProvider(){
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
        Provider* provider = new Provider(bulstat,fName,lName,phone,address);
        return provider;
    }
};

class FileIO{
private:
    string path;
public:
    FileIO();
    void saveProviders();
    vector<Provider> loadProviders;
};
class MyApp{
private:
    ProviderFactory* providerFactory;
    OpticFactory* opticFactory;
    FileIO path();
    vector<Provider*> providers;
public:
    MyApp(){
        providerFactory = new ProviderFactory();
        opticFactory = new OpticFactory();
    }
    void addProvider(){
        Provider* currentProvider = providerFactory->createProvider();
        providers.push_back(currentProvider);
    }
    void addOpticToProvider(Provider* provider){
        Optic* currentOptic = this->opticFactory->CreateOptic();
        provider->addOptic(currentOptic);
    }
    void showProviders(){
        for(unsigned int i = 0; i < providers.size(); i++){
            Provider* currentProvider = providers[i];
            cout << i << ". ";
            currentProvider->showData();
        }
    }
    Provider* getProviderByIndex(){
        this->showProviders();
        cout << "choose the number of the provider, please:" << endl;
        unsigned int number = 0;
        cin >> number;
        if(number >= providers.size()){
            return NULL;
        } else {
            return providers[number];
        }
    }
    double chooseOptic(vector<Optic*> optics, int* usedOptics, int len){
        for(int i = 0; i < len; i++){
            if(usedOptics[i] == 0){
                cout << i << ". " << endl;
                optics[i]->showData();
            }
        }
        cout << endl;
        cout << "choose optic" << endl;
        int choise = 0;
        cin >> choise;
        usedOptics[choise] = 0;
        return optics[choise]->getPrice();
    }
    void buyOptics(){
        Provider* provider = getProviderByIndex();
        vector<Optic*> optics = provider->getOptics();
        int totalOpticsCount = provider->getOptics().size();
        double totalSumForPaying = 0;

        int usedOptics[totalOpticsCount];
        for(int i = 0; i < totalOpticsCount; i++){
            usedOptics[i] = 0;
        }
        while(1){
            int choise = 0;
            cout << "Do you want to choose optic for buying?" << endl;
            cout << "1 -> YES         2 -> NO" << endl;
            if(choise != 1){
                break;
            } else {
                totalSumForPaying += chooseOptic(optics,usedOptics,totalOpticsCount);
            }
        }
        cout << "Total sum: " << totalSumForPaying << endl;
    }

    void startApp(){
        int choise = 0;
        while(choise != -1){
            this->showMenu();
            cin >> choise;
            if(choise == 0){
                break;
            } else if(choise == 1){
                this->addProvider();
            } else if(choise == 2){


                Provider* choisenProvider = this->getProviderByIndex();
                addOpticToProvider(choisenProvider);
                cout << "End of adding optic to provider" << endl;
            } else if(choise == 3){

            } else if(choise == 4){

            } else if(choise == 5){
               this->buyOptics();

            } else if(choise == 6){
                this->showProviders();
            } else if(choise == 7){

            } else if(choise == 8){

            }  else {
                break;
            }
        }
    }
    void showMenu(){
        cout << "0 - exit" << endl;
        cout << "1 - Add provider" << endl;
        cout << "2 - Add optic to provider" << endl;
        cout << "3 - save" << endl;
        cout << "4 - load" << endl;
        cout << "5 - choose provider" << endl;
        cout << "6 - Show providers" << endl;
    }
    void orderOptics();
};
int main()
{
    cout << "Welcome!" << endl;


    MyApp* myApp = new MyApp();
    myApp->startApp();

    cout << "Thank you for using us" << endl;
    return 0;
}
