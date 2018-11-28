#include <iostream>
#include <vector>

using namespace std;

/**
Дефинирайте клас, описващ дати от календара. Дефинирайте за него подходящите get и set методи.
Дефинирайте конструктор по подразбиране и такъв с параметри за задаване на дата. Да се дефинира клас
посещения на пациенти при личен доктор с данни: ЕГН, Име на пациента, Оплаквания, Дата на прегледа,
 Списък
с предишни оплаквания и съответна диагноза, предписани лекарства до 5 бр. Предефиниране на операцията << за
извеждане на данните. Данните да се съхраняват във файл.
Въвеждане, корекция на данните и изтриване. Извеждане на справки:
Направете масив от пациенти.
1. Извеждане на информация за пациенти прегледани последния месец;
2.Извеждане на информация за пациенти с оплаквания;
3.Определяне за най-често срещана диагноза;
**/

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(){}
    Date(int, int, int);
    ~Date();
    int getDay();
    int getMonth();
    int getYear();
};
Date::Date(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
}

Date::~Date(){
    cout<<"Date destroyed"<<endl;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

class Issue{
private:
    string diagnose;
    string medicines[5];
public:
    Issue(){}
    Issue(string, string*);
    ~Issue();
};

Issue::Issue(string diagnose, string* medicines){
    this -> diagnose = diagnose;
    for(int i = 0; i < 5; i++){
        this -> medicines[i] = medicines[i];
    }
}

Issue::~Issue(){
    cout<<"Issue destroyed"<<endl;
}

class Patient{
private:
    string egn;
    string name;
    string issue;
    Date dateVisit;
    vector<Issue> issues;
public:
    Patient(){}
    Patient(string, string, string, Date, vector<Issue>);
    ~Patient();
    friend ostream& operator<<(ostream& stream, const Patient& patient);
};

Patient::Patient(string egn, string name, string issue, Date dateVisit, vector<Issue> issues){
    this -> egn = egn;
    this -> name = name;
    this -> issue = issue;
    this -> dateVisit = dateVisit;
    this -> issue = issue;
}

Patient::~Patient(){
    cout<<"Patient died"<<endl;
}

ostream& operator<<(ostream& stream, const Patient& patient){
    stream<<patient.egn<<" "<<patient.name<<" "<<endl;
    return stream;
}

int main()
{
    Date date1(1,2,3);
    string arr[5];
    Issue i1("", arr);
    Issue i2("", arr);
    vector<Issue> issue;
    issue.push_back(i1);
    issue.push_back(i2);


    Patient p("Pesho", "Gosho", "Misho", date1, issue);


    cout<<p;
    cout << "Hello world!" << endl;
    return 0;
}
