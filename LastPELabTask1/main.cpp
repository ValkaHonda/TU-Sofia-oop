#include <iostream>
#include <vector>
/*
Задача 1 от последното упражнение при Константинов.
Клас дата с член променливи:
-> ден
-> месец
-> година
, които са цели числа.
Имаме задължително копиращ конструктор.
Да се проектира клас спестовен вложител в банка с член променливи:
име
сума
и
дата.
Задължително член функция, която пресмята годишно получената
лихва в случай, че тя е 5% просто годишна лихва.
Използвайте при необходимост get and set methods.
Направете в мейна масив от обекти от клас спестовен вложител
и да се извежда онзи вложител, който е получил най-голям
приход от лихвите.

Bonus point:
На контролното е възможно да имаме следните 4 функционалности:
-> min
-> max
-> interest(лихва)
лихва = сума * лихвен процент/100 * брой месеци/12
нарастналата сума = старата сума * (1 + (12 - месеците)* лихвения процент)
                                          -------------------------------
                                                        100 * 12
-> Sort
*/
using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int, int, int);
    Date(){}
    Date(const Date &); ///Copy Constructor
    int getMonth(){
        return month;
    }
};

Date::Date(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
}

Date::Date(const Date &obj){///Copy Constructor
    this -> day = obj.day; /// this -> day points to the new object.
                            ///obj.day references to the old object

    this -> month = obj.month;
    this -> year = obj.year;
}

class Depositor{
private:
    string name;
    Date date; ///Example of composition.
    double sum;
public:
    Depositor(string, Date, double);
    Depositor(){}
    double calcInterest();
    string getName(){
        return name;
    }
};

Depositor::Depositor(string name, Date date, double sum){
    this -> name = name;
    this -> date = date;
    this -> sum = sum;
}

double Depositor::calcInterest(){
    int period = 12 - date.getMonth(); ///правим го така, защото се търси лихвата до края на годината
                                    /// така каза Коцето за тази задача
    double interest = sum * 5/100 * period/12;
    return interest;
}
int main()
{
    ///Dates will be used for depositor objects.
    Date date1(1,2,2018);
    Date date2(1,5,2018);
    Date date3(1,11,2018);

    ///Below we use the dates.
    Depositor client1("Lenny1", date1, 250);
    Depositor client2("Lenny2", date2, 2500);
    Depositor client3("Lenny3", date3, 25000);

    vector<Depositor> depositors;
    depositors.push_back(client1);
    depositors.push_back(client2);
    depositors.push_back(client3);

    ///Така се решава задачата, ако ни искат само максималната лихва и не ни пука на кого е.
    double maxInterest = depositors[0].calcInterest(); ///Взимаме 1вия елемент на масива.
    for(unsigned int i = 1; i < depositors.size(); i++){ ///Обхождаме масива.
        double currentInterest = depositors[i].calcInterest(); ///От всеки елемент взимаме лихвата
        if(maxInterest < currentInterest){ ///Сравняваме я с досегашната максимална лихва.
            maxInterest = currentInterest; ///Ако текущата лихва е по-голяма, то максималната лихва я поглъша(присвоява)
        }
    }
    cout<<"Max interest: "<<maxInterest<<endl;

    ///Така се решава, ако ни пука на кого е.
    ///Как?
    ///Правим сортировка по лихвите(bubble sort) във възходящ ред
    ///След сортировката последния обект от масива съдържа най-високата лихва.

    ///Стъпка 1: -> Сортировка
    for(unsigned int i = 0; i < depositors.size()-1; i++){

        for(unsigned int j = 0; j < depositors.size()-1; j++){
            double currentInterest = depositors[j].calcInterest();
            double nextInterest = depositors[j+1].calcInterest();
            if(currentInterest > nextInterest){
                ///We do swap
                Depositor temp; ///This will be a temporary placeholder.
                temp = depositors[j];
                depositors[j] = depositors[j+1];
                depositors[j+1] = temp;
            }
        }
    }
    ///Стъпка 2: -> Извеждаме резултата от последния елемент на масива.
    ///Как да сметнем индекса на последния елемент? -> depositors.size() - 1
    cout<<"Person with max interest: "<<depositors[depositors.size() - 1].getName()<<endl;
    return 0;
}
