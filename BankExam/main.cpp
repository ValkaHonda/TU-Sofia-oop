#include <iostream>
#include <vector>

using namespace std;

/*
Банка има различни видове сметки за своите клиенти - депозитни сметки и кредитни сметки. Всички сметки
имат име на клиент, баланс и лихвен процент. В депозитни сметки няма право да се депозират и теглят суми.
В кредитните сметки може да се депозират пари. За всички сметки може да се изчисли размерът на лихвата им
за определен период(в месеци). В общия случай се изчислява както следва: брой на месеците * лихвения %.
Демонстрирайте функционалността на задачата чрез създаване на масив от различни банкови сметки и
намирането на сметката с най-висок лихвен %.
*/

class AbstractAccount{
private:
    string clientName;
    double balance;
    double percent;
public:
    AbstractAccount(string, double, double);
    virtual ~AbstractAccount(); ///when a class will be a basic class for inheritance destructor must be virtual
    virtual double calculateInterest(int)=0; ///pure virtual method(very important if the class is abstract! VIC)
    double getPercent(){
        return percent;
    }
    double getBalance(){
        return balance;
    }
    void setBalance(double money){
        balance = money ;
    }
};

AbstractAccount::AbstractAccount(string clientName, double balance, double percent){
    this->clientName = clientName;
    this->balance = balance;
    this->percent = percent;
}

AbstractAccount::~AbstractAccount(){
    cout<<"Abstract account destroyed"<<endl;
}
class DepositAccount:public AbstractAccount{
private:
    ///all of the properties are in the abstract account(code reuse)
public:
   DepositAccount(string, double, double);

   ///override of the pure virtual method from the abstract class
   double calculateInterest(int);
};

DepositAccount::DepositAccount(string clientName,
                               double balance, double percent):AbstractAccount(clientName, balance, percent){
///when calling the parent constructor we always pass the parameters with their names only!
///very important -> Don't give variables type(ONLY NAMES)!

}

double DepositAccount::calculateInterest(int months){
    double interest = months * getPercent();
    return interest;
}
class CreditAccount:public AbstractAccount{
private:
     ///all of the properties are in the abstract account(code reuse)
public:
    CreditAccount(string, double, double);
    void inputMoney(double);
    void outputMoney(double);
    ///override of the pure virtual method from the abstract class
    double calculateInterest(int);
};

double CreditAccount::calculateInterest(int months){
    double interest = months * getPercent();
    return interest;
}

CreditAccount::CreditAccount(string clientName,
                             double balance, double percent):AbstractAccount(clientName, balance, percent){
///when calling the parent constructor we always pass the parameters with their names only!
///very important -> Don't give variables type(ONLY NAMES)!
}

void CreditAccount::inputMoney(double money){
    setBalance(getBalance() + money);
}

void CreditAccount::outputMoney(double money){
    setBalance(getBalance() - money);
}

int main()
{
    cout << "Hello world!" << endl;
    vector<AbstractAccount*> arr;
    DepositAccount account1("Lenny", 80, 10);
    DepositAccount account2("Lenny", 600, 10);
    DepositAccount account3("Elly", 200, 10);
    CreditAccount account4("Lenny", 80, 10);

    arr.push_back(&account1);
    arr.push_back(&account2);
    arr.push_back(&account3);
    arr.push_back(&account4);

    return 0;
}
