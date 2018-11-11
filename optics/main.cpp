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
    string getData() const;
    string getOpticType();
    string getThickness();
    string getMaterial();
    double getDiopter();
    double getPrice();
    string toFileLineString();
    friend ostream& operator<<(ostream&, const Optic&);
};

ostream& operator<<(ostream& os, const Optic& optic){
    os << '\t' << "Optic type: " << optic.opticType << endl;
    os << '\t' << "thickness: " << optic.thickness<< endl;
    os << '\t' << "material: " << optic.material << endl;
    os << '\t' << "diopter: " << optic.diopter << endl;
    os << '\t' << "price: " << optic.price << endl;
    return os;
}
Optic::Optic(){}
Optic::Optic(string opticType,string thickness,string material,double diopter,double price){
        this->opticType = opticType;
        this->thickness = thickness;
        this->material = material;
        this->diopter = diopter;
        this->price = price;
}
string Optic::getOpticType(){
    return opticType;
}
string Optic::getThickness(){
    return thickness;
}
string Optic::getMaterial(){
    return material;
}
double Optic::getDiopter(){
    return diopter;
}
string Optic::getData() const{
    stringstream ss;
    ss << '\t' << "Optic type: " << opticType << endl;
    ss << '\t' << "thickness: " << thickness<< endl;
    ss << '\t' << "material: " << material << endl;
    ss << '\t' << "diopter: " << diopter << endl;
    ss << '\t' << "price: " << price << endl;
    return ss.str();
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
    string getFName() const;
    string showOptics() const;

    void addOptic(Optic newOptic);
    vector<Optic> getOptics();
    string toFileLineString();
    void setOptics(vector<Optic>);
    friend ostream& operator<<(ostream&, const Optic&);
    string getLName() const;
    string getBulstat() const;
    string getPhone() const;
    string getAddress() const;
};
string Provider::getFName() const{
    return fName;
}
ostream& operator<<(ostream& os, const Provider& provider){
    os << "First name: " << provider.getFName() << endl;

    os << "Last name: " << provider.getLName() << endl;
    os << "Bulstat: " << provider.getBulstat() << endl;
    os << "Phone: " << provider.getPhone() << endl;
    os << "Address: " << provider.getAddress() << endl;
    os << "Optics:" << endl;
    os << provider.showOptics();
    return os;
}
void Provider::setOptics(vector<Optic> optics){
    this->optics = optics;
}
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
string Provider::showOptics() const{
    stringstream ss;
    for(unsigned int i = 0; i < optics.size(); i++){
        ss << i << "." << endl;
        ss << optics[i].getData() << endl;
    }
    return ss.str();
}
string Provider::getLName() const{
    return lName;
 }
string Provider::getBulstat() const{
    return bulstat;
}
string Provider::getPhone() const{
    return phone;
}
string Provider::getAddress() const{
    return address;
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
vector<Provider> FileIO::loadProviders(){
    vector<Provider> providers;
    string line;
    ifstream myfile (path);

    if (myfile.is_open()){
        int providerFieldCounter = 0;
        string bulstat;
        string fName;
        string lName;
        string phone;
        string address;

        while ( getline (myfile,line) ){
            if(line == "TU-End"){
                break;
            }
            if(providerFieldCounter == 0){
                bulstat = line;
                providerFieldCounter++;
            } else if(providerFieldCounter == 1){
                fName = line;
                providerFieldCounter++;
            } else if(providerFieldCounter == 2){
                lName = line;
                providerFieldCounter++;
            }else if(providerFieldCounter == 3){
                phone = line;
                providerFieldCounter++;
            }else if(providerFieldCounter == 4){
                address = line;
                Provider newProvider(bulstat,fName,lName,phone,address);
                providerFieldCounter++;
                providers.push_back(newProvider);
            }else {
                if(line == "-->"){
                    string opticType;
                    string thickness;
                    string material;
                    double diopter;
                    double price;
                    int opticCounter = 0;
                    string opticLine;
                    vector<Optic> optics;
                    while ( getline (myfile,opticLine) ){
                        if(opticLine == "<--"){
                            // add optics to provdires
                            if(optics.size() > 0){
                                providers[providers.size()-1].setOptics(optics);
                            }
                            break;
                        }
                        if(opticCounter == 0){
                            opticType = opticLine;
                            opticCounter++;
                        } else if(opticCounter == 1){
                            thickness = opticLine;
                            opticCounter++;
                        } else if(opticCounter == 2){
                            material = opticLine;
                            opticCounter++;
                        } else if(opticCounter == 3){
                            diopter = stod(opticLine);
                            opticCounter++;
                        } else if(opticCounter == 4){
                            price = stod(opticLine);
                            Optic newOptic(opticType,thickness,material,diopter,price);
                            optics.push_back(newOptic);
                            opticCounter = 0;
                        } else {
                            cout << "error" << endl;
                        }
                    }
                }
                providerFieldCounter = 0;
            }
        }
        myfile.close();
        return providers;
    } else{
        cout << "Unable to open file";
        return providers;
    }
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

void showMenu(){
    cout << "0. Exit." << endl;
    cout << "1. Add provider." << endl;
    cout << "2. Show providers." << endl;
    cout << "3. Save to File." << endl;
    cout << "4. Load from File." << endl;
    cout << "5. Add new optic to current provider." << endl;
    cout << "6. Calculate the price for a number of optics from a provider." << endl;
}
void continueMenu(){
    cout << "0. Exit." << endl;
    cout << "1. Processed." << endl;
}

class AppController{
private:
    OpticFactory opticFactory;
    ProviderFactory providerFactory;
    FileIO file;
    vector<Provider> providers;
    bool isThereSomethingLeft(int*, int);
    Provider* choseProvider();
    void chooseOptics(vector<Optic> currentOptics);
public:
    AppController(ProviderFactory, OpticFactory, FileIO);
    void addProvider();
    void addProvider(Provider);
    void saveToFile();
    void showProviders();
    void loadProviders();
    void addOpticToCurrentProvider();
    void calculatePriceForChoisenOptics();
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
        cout << "Provider " << i << ":"<< endl;
        cout << providers[i] << endl;
    }
}
void AppController::saveToFile(){
    file.saveProviders(providers);
}
void AppController::loadProviders(){
    providers = file.loadProviders();
}
void AppController::addOpticToCurrentProvider(){
    if(providers.size() == 0){
        cout << "There are no providers" << endl;
        return;
    }
    Provider* currentProvider = choseProvider();
    if(currentProvider == NULL){
      cout << "No Provider" << endl;
      int temp;
      cout << "Enter 1 and press Enter." << endl;
      cin >> temp;
      return;
    }
    Optic newOptic = opticFactory.createOptic();
    currentProvider->addOptic(newOptic);


    cout << "Operation complete." << endl;
}
bool AppController::isThereSomethingLeft(int* choisenOptics, int len){
    for(int i = 0; i < len; i++){
        if(choisenOptics[i] == 0){
            return true;
        }
    }
    return false;
}
Provider* AppController::choseProvider(){
     if(providers.size() == 0){
        cout << "There are no providers" << endl;
        return NULL;
    }
    cout << "--> Please choose a provider number:" << endl;
    showProviders();
    cout << "--> Please choose a provider number:" << endl;
    int choise = -1;
    cin >> choise;
    while(choise < 0 || choise >= (int)providers.size()){
        cout << "Please choose a valid provider number!" << endl;
        cin >> choise;
    }
    return &providers[choise];
}
void AppController::chooseOptics(vector<Optic> currentOptics){

    if(currentOptics.size()==0){
        cout << "This provider has no optics" << endl;
        return;
    }
    int opticsSize = currentOptics.size();
    int choisenOptics[opticsSize];
    for(int i = 0; i < opticsSize; i++){
        choisenOptics[i] = 0;
    }

    cout << "This are the optics for the chosen provider:" << endl;

    int stillBying = 1;
    double currentSum = 0;
    while (stillBying == 1 && isThereSomethingLeft(choisenOptics,opticsSize)){
        cout << "Please choose one of the following optics." << endl;
        for(int i = 0; i < opticsSize; i++){
            if(choisenOptics[i] == 1){
                continue;
            } else {
                cout << "Optic " << i << ":" << endl;
                currentOptics[i].getData();
                cout << endl;
            }
        }
        int currentOptic = -1;
        cout << "Please choose an optic." << endl;
        cin >> currentOptic;
        while (currentOptic < 0 && currentOptic >= opticsSize && choisenOptics[currentOptic] == 1){
            cout << "Please choose valid optic" << endl;
            cin >> currentOptic;
        }
        currentSum += currentOptics[currentOptic].getPrice();
        choisenOptics[currentOptic] = 1;
        cout << "Chosen Optics: " << endl;

        for(int i = 0; i < opticsSize; i++){
            if(choisenOptics[i] == 0){
                continue;
            } else {
                cout << "Optic " << i << ":" << endl;
                currentOptics[i].getData();
                cout << endl;
            }
        }
        if(!isThereSomethingLeft(choisenOptics,opticsSize)){
            cout << "There a no more optics to chose" << endl;
            cout << "Total price: " << currentSum << endl;
            cout << "Enter 1 and press Enter to return to main menu." << endl;
            cin >> stillBying;
            return;
        }
        cout << "Total price: " << currentSum << endl;
        cout << "Do you want to buy another Optic from this provider?" << endl;
        continueMenu();
        cin >> stillBying;
    }
}
void AppController::calculatePriceForChoisenOptics(){
    Provider* provider = choseProvider();
    if(provider == NULL){
        cout << "There are no providers" << endl;
        int temp;
        cout << "Enter 1 and press Enter." << endl;
        cin >> temp;
        return;
    }
    vector<Optic> currentOptics = provider->getOptics();
    chooseOptics(currentOptics);
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
        } else if(choise == 4){
            cout << "--> Load from File" << endl;
            cout << endl;
            app.loadProviders();
            cout << "Load complete" << endl;
        } else if(choise == 5){
            app.addOpticToCurrentProvider();
        } else if(choise == 6){
            app.calculatePriceForChoisenOptics();
        }else {
            break;
        }

        int continueChoise = 0;
        continueMenu();
        cin >> continueChoise;
        if(continueChoise == 0){
            break;
        } else {
            system("cls");
            showMenu();
            cin >> choise;
        }

    }
    cout << "Thank you for using us" << endl;
    return 0;
}
