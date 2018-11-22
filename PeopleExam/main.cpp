#include <iostream>
using namespace std;
/* Да се напише програма, която дефинира клас People, определящ човек по име и ЕГН,
а също и производен клас Student на People, който определя понятието студент, като човек,
който има факултетен номер и среден успех. Да се дефинира обект от класа Student и се изведе
дефинирания обект. Да се дефинира клас PStudent, производен на класа Student, реализиращ
понятието студент от платена форма на обучение. Студентът може да получава стипендия
само ако средният му успех е много добър (над 4.50). Реализирайте подходящи методи за
получаване на стойностите на променливите.Реализирайте задачата така че методите на
производните класове да могат пряко да използват наследените член-данни на основните
им класове. Инициализиращите действия да се изпълняват от подходящи конструктори.
Демонстрирайте работата на класовете с подходящи обекти.  */

class People
{
protected: string name, egn;
public:
    People(){};
    People(string, string);
    string getName() {return name;}
};

People::People(string name, string egn)
{this->name = name; this->egn = egn;}

class Student:public People
{
protected: string facNumber; double averageMark;
public:
    Student(){};
    Student(string, string, string, double);
    double getAverageMark(){return averageMark;}
};

Student::Student(string name, string egn, string facNumber, double averageMark):People(name, egn)
{this->facNumber = facNumber; this->averageMark = averageMark;}

class PStudent:public Student
{
private:
public:
    PStudent(string, string, string, double);
    bool receiveScholarship()
    {if(averageMark < 4.50) {return false;}
    else{return true;}
    }
};

PStudent::PStudent(string name, string egn, string facNumber, double averageMark):Student(name, egn, facNumber, averageMark)
{cout << "Paid student constructor." << endl;}

int main()
{
    cout << "Hello world!" << endl;
    Student arr[7];
    PStudent student1("It", "218", "12121616188", 5.00);
    PStudent student2("Its", "666", "12121616007", 3.00);
    PStudent student3("Nevenmieko", "216", "12121616300", 5.99);
    PStudent student4("Sergey", "313", "12121616300", 4.50);
    PStudent student5("Mahaise", "777", "12121616300", 6.00);
    PStudent student6("Antonio", "000", "12121616300", 3.20);
    PStudent student7("Amador", "567", "12121616300", 2.00);
    arr[0] = student1;
    arr[1] = student2;
    arr[2] = student3;
    arr[3] = student4;
    arr[4] = student5;
    arr[5] = student6;
    arr[6] = student7;

    for(int i = 0; i < 7; i++)
        {cout << "Name: " << arr[i].getName() << endl;}

    if(student1.receiveScholarship() == true)
        {cout << "Student 1: " <<student1.getName() << endl;}

for(int i = 0; i<=6; i++)
    {
     for(int j = 0; j<=6; j++)
     {
            if(arr[j].getAverageMark() > arr[j+1].getAverageMark())
            {
            Student tempStudent;
            tempStudent = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tempStudent;
            }
    }
   }
for(int i = 0; i < 7; i++)
{cout << "Average Mark: " <<arr[i].getAverageMark() << endl;}
return 0;
}
