#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
Дефинирайте клас, описващ дати от календара.
Дефинирайте копиращ конструктор и такъв с параметри за задаване на дата.
Клас описващ студент - Име, Факултетен номер, Дата на раждане и Среден успех.
Метод, който сравнява за по-малко по даден параметър обект с текущия.
Демонстрирайте работата на класовете със създаване на колекция от студенти
и сортирайте студентите по успех в низходящ ред
**/

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int, int, int);
    Date(const Date &);
    Date(){}
    string getInfo();
};

Date::Date(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
}

Date::Date(const Date &obj){
    this -> day = obj.day;
    this -> month = obj.month;
    this -> year = obj.year;
}

string Date::getInfo(){
    stringstream stream;
    stream<<day<<" "<<month<<" "<<year<<endl;
    string result = stream.str();
    return result;
}

class Student{
private:
    string name;
    string facNumb;
    Date birth;
    double average;
public:
    Student(string, string, Date, double);
    Student(){}
    bool compare(Student);
    string getInfo(); ///мое допълнение :)
    double getAverage();
};

Student::Student(string name, string facNumb, Date birth, double average){
    this -> name = name;
    this -> facNumb = facNumb;
    this -> birth = birth;
    this -> average = average;
}

bool Student::compare(Student otherStudent){
    if(average >= otherStudent.getAverage()){
        return true;
    }
    else {
        return false;
    }
}

double Student::getAverage(){
    return average;
}

string Student::getInfo(){
    stringstream stream;
    stream<<name<<" "<<facNumb<<" "<<birth.getInfo()<<" "<<average<<endl;
    string result = stream.str();
    return result;
}

int main()
{
    Date date1(16, 6, 1993);
    Date date2(15, 7, 2001);
    Date date3(19, 4, 1998);
    Date date4(15, 3, 1999);
    Student student1("Ivan", "16269", date1, 4.89);
    Student student2("Dragan", "9652", date2, 4.52);
    Student student3("Petkan", "15216", date3, 3.69);
    Student student4("Katq", "12126", date4, 5.12);

    vector<Student> arr;
    arr.push_back(student1);
    arr.push_back(student2);
    arr.push_back(student3);
    arr.push_back(student4);
    cout<<endl<<"Before sorting"<<endl;
    for(unsigned int i = 0; i < arr.size(); i++){ /// before sort
        cout<<arr[i].getInfo()<<endl;
    }

    for(unsigned int i = 0; i < arr.size() - 1; i++){
        for(unsigned int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j].compare(arr[j+1]) == false){
                Student temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<<endl<<"After sorting"<<endl;
    for(unsigned int i = 0; i < arr.size(); i++){ /// after sort
        cout<<arr[i].getInfo()<<endl;
    }

    return 0;
}
