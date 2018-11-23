#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>

using namespace std;

/**
Дефинирайте клас, описващ дати от календара. Дефинирайте за него подходящите get и set методи.
Дефинирайте конструктор по подразбиране и такъв с параметри за задаване на дата. Дефинирайте
клас, описващ студент, като включите следните данни: Име, Факултетен номер, Дата на раждане –
използвайте класа описващ дати, Среден успех. Дефинирайте подходящите get и set методи.
Дефинирайте конструктор по подразбиране и с параметри за инициализиране на обекта. Дефинирайте
метод, който по зададен параметър дата, връща възрастта на студента като брой навършени години.
Да се определя средния успех на потока. Да се извеждат студентите от потока, които са между 18
и 26 години включително. Данните да се съхраняват във файл.
**/

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int, int, int);
    Date(){}
    int getDay();
    int getMonth();
    int getYear();
};

Date::Date(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
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

class Student{
private:
    string name;
    string facNumber;
    Date birthDate;
    double average;
public:
    Student(string, string, Date, double);
    Student(){}
    int getAge(Date birthDate);
    double getAverage();
    string getName();
};

Student::Student(string name, string facNumber, Date birthDate, double average){
    this -> name = name;
    this -> facNumber = facNumber;
    this -> birthDate = birthDate;
    this -> average = average;
}

double Student::getAverage(){
    return average;
}

string Student::getName(){
    return name;
}

int Student::getAge(Date now){
    int age = -1;
    if(now.getYear() < birthDate.getYear()){
        cout<<"Invalid date"<<endl;
        return age;
    } else {
        age = now.getYear() - birthDate.getYear();
        if(now.getMonth() > birthDate.getMonth()){
            return age;
        } else if(now.getMonth() == birthDate.getMonth()){
                if(now.getDay() >= birthDate.getDay()){
                    return age;
                }else{
                    return age - 1;
                }
        }else{
            return age - 1;
        }
    }
    return age;
}
int main()
{
    Date date1(24, 3, 2000);
    Date date2(22, 5, 1999);
    Date date3(18, 3, 2001);
    Date date4(13, 7, 1998);
    Date date5(1, 8, 1995);
    Date currentDate(23, 11, 2018);
    Student student1("Pucky", "121216120", date1, 5.03);
    Student student2("Lucky", "1212161560", date2, 6);
    Student student3("It", "121216568", date3, 2.65);
    Student student4("He", "121216152", date4, 4.65);
    Student student5("He2", "121216152", date5, 4.65);

    vector<Student> arr;
    arr.push_back(student1);
    arr.push_back(student2);
    arr.push_back(student3);
    arr.push_back(student4);
    arr.push_back(student5);

    double averageMark = 0;

    for(unsigned int i = 0; i< arr.size(); i++){
        averageMark += arr[i].getAverage();
        if(arr[i].getAge(currentDate) >= 18 && arr[i].getAge(currentDate) <= 26){
            cout<<"Student: "<<arr[i].getName()<<endl;
        }
    }
    cout<<"Average mark: "<<averageMark/arr.size()<<endl;

    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    for(unsigned int i = 0; i < arr.size(); i++){
        myfile<<arr[i].getName()<<endl;
    }
    myfile.close();


    return 0;
}
