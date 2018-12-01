#include <iostream>
#include <string.h>
using namespace std;

class Principal
{
private: string name; int age; string phone;
public: Principal(){}; ~Principal();
        Principal(string, int, string);
string getName()const{return name;}
    int getAge()const{return age;}
string getPhone()const{return phone;}
};

Principal::~Principal(){cout << "Principal killed."<< endl;}
Principal::Principal(string name, int age, string phone)
{this->name = name; this->age = age; this->phone = phone;}

class School
{
private: char* name; int number, studentCount; Principal principal;
public: School(){}; ~School();
        School(char*, int, int, Principal);
        School(const School& school);
friend ostream& operator<<(ostream& stream, const School& school);
Principal getPrincipal() {return principal;}
int getStudentCount() {return studentCount;}
School& operator=(const School& school);
};
School& School::operator=(const School& school)
{
int textSize = strlen(school.name);
this->name = new char[textSize+1];
strcpy(this->name, school.name);
this->number = school.number;
this->studentCount = school.studentCount;
this->principal = school.principal;
return *this;
}


School::School(char* name, int number, int studentCount, Principal principal)
{
/*this->name = name;  Instead, we use the following:
1) Създаване променлива textSize, в която присвояваме големината на string-а, като използваме strlen.
2) Заделяме памет на указателя на класа textSize+1 (+1 заради терминиращата 0).
3) Чрез strcpy прехвърляме текста от подадения name в this->name.*/


/*1*/ int textSize = strlen(name);
/*2*/ this->name = new char[textSize+1];
/*3*/ strcpy(this->name, name);
this->number = number;
this->studentCount = studentCount; this->principal = principal;
}

School::~School() {cout <<"School burned down."<< endl; delete [] name;}
School::School(const School& school)
{
int textSize = strlen(school.name);
this->name = new char[textSize+1];
strcpy(this->name, school.name);
this->number = school.number;
this->studentCount = school.studentCount; this->principal = school.principal;
}

ostream& operator<<(ostream& stream, const School& school)
{
for (unsigned int i = 0; i < strlen(school.name); i++)
{
stream << school.name[i] << endl;}
stream << school.number <<" "<<school.studentCount <<" "<< school.principal.getName() << endl;
stream << school.principal.getAge() <<" "<< school.principal.getPhone() << endl;
return stream;
}

int main()
{
Principal firstPrincipal("Nelly Petrova", 76, "9575544");
Principal secondPrincipal("Garfield", 100, "313");
Principal thirdPrincipal("Menta Petkanova", 50, "876");
char name[100];
name[0] = 'T';
name[1] = 'U';
name[2] = 'E';
name[3] = 'S';
name[4] = '\0';
strcpy(name,"abvv");
School schools[3];
School firstSchool(name, 33, 1000, secondPrincipal);
School secondSchool(name, 81, 2000, firstPrincipal);
School thirdSchool(name, 43, 3000, thirdPrincipal);
schools[0] = firstSchool;
schools[1] = secondSchool;
schools[2] = thirdSchool;

cout << "Task 1:"<< endl;
int averageStudents = 0;
for(int i = 0; i < 3; i++)
{averageStudents +=schools[i].getStudentCount();}
cout << averageStudents/3 << endl;

cout <<"Task 2:"<< endl;

for (int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
if (schools[j].getPrincipal().getAge() > schools[j+1].getPrincipal().getAge())
{
School temporary;
temporary = schools[j];
schools[j] = schools[j+1];
schools[j+1] = temporary;
}}}

cout << schools[0] << endl;
cout <<"Task 3:"<< endl;
for (int i = 0; i < 3; i++)
    {if (schools[i].getPrincipal().getPhone() == "9575544")
    {
        cout << "Bravo." << endl;
        cout << schools[i] << endl;}
    }



return 0;
}
