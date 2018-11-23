#include <iostream>
#include <vector>
/**
Дефинирайте клас, който описва банкова сметка:
- име на клиента
- номер на сметка
- баланс
- лихвен %.
Класът да има конструктор(номер на сметка, баланс, лихвен % = 1,2). Класът има член функция,
която изчислява размерът на лихвата за определен период, зададен в месеци. Член фукция за
депозиране и теглене на суми.
Напишете клас за спестовна сметка, който е наследник на горния
клас. От класът е възможно да се теглят пари на точно определена дата, зададена като
член-променлива на класа. Напишете main() функция, в която имате масив(колекция) от спестовни
сметки и търси и извежда номер и баланса на сметките, които могат да се теглят с днешна дата.
**/
using namespace std;

class BankAccount{
private:
    string name;
    string accountNumber;
    double balance;
    double interestPercent;
public:
    BankAccount(string, string, double, double);
    BankAccount(){}
    virtual ~BankAccount(){}
    double calcInterest(int months);
    void transferMoney(double);
    string getAccountNumber();
    double getBalance();
};

BankAccount::BankAccount(string name, string accountNumber, double balance, double interestPercent){
    ///double interestPercent = 1.2 -> ако не се подаде този параметър, неговата стойност е 1,2
    this -> name = name;
    this -> accountNumber = accountNumber;
    this -> balance = balance;
    this -> interestPercent = interestPercent;
}

double BankAccount::calcInterest(int months){
    double interest = interestPercent * months;
    return interest;
}

void BankAccount::transferMoney(double sum){
    balance += sum;
}

string BankAccount::getAccountNumber(){
    return accountNumber;
}

double BankAccount::getBalance(){
    return balance;
}

class DepositorAccount:public BankAccount{
private:
    string date;
public:
    DepositorAccount(string, string, double, double, string);
    DepositorAccount(){}
    void transferMoney(double, string);
    string getDate();
};

DepositorAccount::DepositorAccount(string name, string accountNumber, double balance, double interestPercent,
                                   string date):BankAccount(name, accountNumber, balance, interestPercent){
    this -> date = date;
}

void DepositorAccount::transferMoney(double sum, string d){
    if(date == d){
        BankAccount::transferMoney(sum); ///По този начин извикваме старата версия на transferMoney от базовия клас.
    }
}

string DepositorAccount::getDate(){
    return date;
}

int main()
{
    DepositorAccount account1("Pesho", "123", 200, 1.2, "21.02.2018");
    DepositorAccount account2("Gosho", "124", 300, 1.2, "26.02.2018");
    DepositorAccount account3("Misho", "125", 400, 1.2, "25.02.2018");
    DepositorAccount account4("Tosho", "126", 500, 1.2, "24.02.2018");


    vector<DepositorAccount> arr;
    arr.push_back(account1);
    arr.push_back(account2);
    arr.push_back(account3);
    arr.push_back(account4);

    for(int i = 0; i < arr.size(); i++){
        if(arr[i].getDate() == "21.02.2018"){

            cout<<"Account number: "<<arr[i].getAccountNumber()<<endl;
            cout<<"Balance: "<<arr[i].getBalance()<<endl;
        }
    }
    return 0;
}
