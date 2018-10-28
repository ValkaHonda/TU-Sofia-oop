#include <iostream>
using namespace std;
class MyDate
{
 private: int year, month, day;
 public: MyDate(int, int, int);
 MyDate();
 MyDate(const MyDate &date);
 int getYear();
};

MyDate::MyDate(int year, int month, int day)
{this->year = year; this->month = month; this->day = day;}
MyDate::MyDate(){}

MyDate::MyDate(const MyDate &date)
{this->year = date.year; this->month = date.month; this->day = date.day;}

int MyDate::getYear() {return year;}

class Student
{
 private: string name, facul_number; double average_mark; MyDate birthday;
 public: Student(string, string, double, MyDate);
 Student(){}
 int compareMarks(Student otherStudent);
 string getName();
 double getMark();
};

Student::Student(string name, string facul_number, double average_mark, MyDate birthday)
{this->name = name; this->facul_number = facul_number; this->average_mark = average_mark; this->birthday = birthday;}
Student::compareMarks(Student otherStudent)
{
      if(this->average_mark < otherStudent.average_mark) {return -1;}
 else if(this->average_mark > otherStudent.average_mark) {return 1;}
 else                                                    {return 0;}
}
string Student::getName() {return name;}
double Student::getMark() {return average_mark;}
int main()
{

 MyDate firstDate(1997, 6, 3);
 MyDate secondDate(1997, 9, 12);
 MyDate thirdDate(2002, 2, 3);
 //Student* = new Student("Rossy", "121216123", 5.50, firstDate);
 Student* students[3];
 Student* firstStudent = new Student("Rossy", "121216123", 5.50, firstDate);
 Student* secondStudent = new Student("In4y", "121216007", 4.00, secondDate);

 Student* thirdStudent = new Student("Emily", "121216310", 4.50, thirdDate);
 students[0] = firstStudent;
 students[1] = secondStudent;
 students[2] = thirdStudent;



 for(int i = 0; i < 3; i++) {students[i]->getName(); students[i]->getMark();
 cout << "Name: " << students[i]->getName() << "; Average Mark: " << students[i]->getMark() <<endl;}
 cout << endl;

 for(int i = 0; i < 3; i++)
{
for (int j = 1; j < 3; j++)
 {
  if(students[j]->compareMarks((*students[j-1])) == true)
    {Student* temporary = students[j];
     students[j] = students[j-1];
     students[j-1] = temporary;}
 }
}
 for(int i = 0; i < 3; i++) {students[i]->getName(); students[i]->getMark();
 cout << "Name: " << students[i]->getName() << "; Average Mark: " << students[i]->getMark() <<endl;}
 Student fourthStudent("Despair", "121216165", 3.00, firstDate);
 Student fifthStudent("WWW", "121216000", 2.00, thirdDate);
 cout << " " << endl;
 cout << "This is a test." << endl;
 cout << fifthStudent.getName() << endl;
 cout << fourthStudent.getName() << endl;
 fourthStudent = fifthStudent;
 cout << fifthStudent.getName() << endl;
 cout << fourthStudent.getName() << endl;
 cout << "Final Bubble Sort: for the exam" << endl;

Student s1("Dexter", "121216333", 6.00, secondDate);
 Student s2("James", "121216666", 4.20, firstDate);
 Student s3("Wendy", "121216354", 5.00, thirdDate);

 Student s[3];
 s[0] = s1;
 s[1] = s2;
 s[2] = s3;

for(int i = 0; i < 3; i++)
 {
for(int j = 1; j < 3; j++)
    {
     if(s[j-1].compareMarks(s[j]))
        {

         Student tempStudent = s[j];
         s[j] = s[j-1];
         s[j-1] = tempStudent;
        }
    }
 }
 cout << "Printing an array of students after normal sorting." << endl;
 for(int i = 0; i < 3; i++)
    {
     cout << s[i].getName() << " " << s[i].getMark() << endl;
    }
 return 0;
}
