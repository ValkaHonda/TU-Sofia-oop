#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class Author
{
private: char* name; int birthYear;
public: Author(){}; ~Author();
        Author(char*, int);
        Author(const Author&);
        void printName();
        int getYear();
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

int Author::getYear(){
    return birthYear;
}

class Comicbook
{
private: string title; Author author;
         double price; int number;
         static int count;


public: Comicbook(){}; ~Comicbook(){};
        Comicbook(string, Author, double);
        int getNumber() {return number;}
        friend bool compare(Comicbook, Comicbook);
        Author getAuthor();
};

Comicbook::Comicbook(string title, Author author, double price)
{
this->title = title; this->author = author; this->price = price;
this->number = count; count++;
}

int Comicbook::count = 1;

bool compare(Comicbook comic1, Comicbook comic2){
    if(comic1.price < comic2.price){
        return true;
    }
    return false;
}

Author Comicbook::getAuthor(){
    return author;
}

int main()
{
    Author firstAuthor("Meh\0", 2009);
    Author secondAuthor("Eh\0", 2010);
    Author thirdAuthor("M\0", 2000);
    Comicbook firstComic("Title1", firstAuthor, 10);
    Comicbook secondComic("Title2", secondAuthor, 15);
    Comicbook thirdComic("Title2", thirdAuthor, 15);

    cout << firstComic.getNumber() << endl;
    cout << secondComic.getNumber() << endl;
    cout << thirdComic.getNumber() << endl;

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
    vector<Comicbook> arr;
    arr.push_back(firstComic);
    arr.push_back(secondComic);
    arr.push_back(thirdComic);

    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j].getAuthor().getYear() > arr[j + 1].getAuthor().getYear()){
                Comicbook temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = arr[j];
            }
        }
    }
    cout<<"result "<<endl;

    cout<<arr[0].getNumber()<<endl;
    return 0;
}
