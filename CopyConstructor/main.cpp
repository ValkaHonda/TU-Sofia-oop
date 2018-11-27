#include <iostream>
#include <string.h>
using namespace std;
class Author
{
private: char* name; int birthYear;
public: Author(){}; ~Author();
        Author(char*, int);
        Author(const Author&);
void printName();
};
Author::Author(char* name, int birthYear)
{
    //Step 1. Взимаме дължината на думата.
    int textSize = strlen(name);
    //Step 2. Заделяме памет за тази дължина+1 заради терминиращата нула.
    this->name = new char[textSize+1];
    //Step 3. Прехвърляме текста.
    strcpy(this->name, name);


this->birthYear = birthYear;}
Author::~Author()
{delete [] name;}

Author::Author(const Author& oldObject)
{
    int textSize = strlen(oldObject.name);
    this->name = new char[textSize+1];
    strcpy(this->name, oldObject.name);
    this->birthYear = oldObject.birthYear;}
void Author::printName()
{
for (int i = 0; i < 4; i++)
{cout << name[i];}
 cout << endl;
}

class Comicbook
{
private: string title; Author author;
         double price; int number;
         static int count;


public: Comicbook(){}; ~Comicbook(){};
        Comicbook(string, Author, double);
        int getNumber() {return number;}
};

Comicbook::Comicbook(string title, Author author, double price)
{
this->title = title; this->author = author; this->price = price;
this->number = count; count++;
}

int Comicbook::count = 1;


int main()
{
    Author firstAuthor("Meh", 2000);
    Comicbook firstComic("Title1", firstAuthor, 10);
    Comicbook secondComic("Title2", firstAuthor, 15);
    Comicbook thirdComic("Title2", firstAuthor, 15);
    Comicbook fourthComic("Title2", firstAuthor, 15);
    cout << firstComic.getNumber() << endl;
    cout << secondComic.getNumber() << endl;
    cout << thirdComic.getNumber() << endl;
    cout << fourthComic.getNumber() << endl;
    /*
    char* name = new char[5];
    name[0] = 'h';
    name[1] = 'e';
    name[2] = 'l';
    name[3] = 'l';
    name[4] = '/0';

    Author firstAuthor(name, 2000);
    firstAuthor.printName();

    name[0] = 'd';
    name[1] = 'u';
    name[2] = 'c';
    name[3] = 'k';
    name[4] = '/0';

    firstAuthor.printName();
    */

    return 0;
}
