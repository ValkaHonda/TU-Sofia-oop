#include <iostream>
using namespace std;
/*
Направете абстрактен клас Музикален Инструмент с член-променливи име, година на производство и тип(струнен, клавишен...).
Добавете абстрактен метод printInfo(), извеждащ информацията за инструмента.
Създайте клас Китара, разширяващ Музикален Инструмент и добавящ член-променлива брой струни.
Създайте клас Пиано, също разширяващ Музикален Инструмент, добавящ член-променлива брой октави.
Направете масив от инструменти. Сортирайте по година на производство във възходящ ред.
Изведете информацията за всеки инструмент. Успех! ^_^
*/
class MusicalInstrument
{
private: string name; int year; string type;
///При наследяване, деструкторът на базовия клас е virtual!
public: MusicalInstrument(){}; virtual ~MusicalInstrument();
        MusicalInstrument(string, int, string);
///Абстрактен метод:
        virtual void printInfo() = 0;
        string getName() {return name;}
           int getYear() {return year;}
        string getType() {return type;}
};

MusicalInstrument::MusicalInstrument(string name, int year, string type)
{this->name = name; this->year = year; this->type = type;}

MusicalInstrument::~MusicalInstrument() {cout <<"Instrument destroyed."<< endl;}
///Това не знам дали се пише, няма много смисъл от него, тъй като се предефинира:
///-> Ако класът е абстрактен и този метод е абстрактен, НЕ се пише тяло!!!
/*
void MusicalInstrument::printInfo()
{cout<<"Info: "<< name <<", "<< year <<", "<< type <<"."<< endl;}
*/

class Guitar:public MusicalInstrument
{
private: int stringCount;
public: Guitar(){}; ~Guitar();
        Guitar(string, int, string, int);
        void printInfo();
        int getStringCount() {return stringCount;}
};
///Винаги викаме конструктора на базовия клас с параметри само по име!
Guitar::Guitar(string name, int year, string type, int stringCount):MusicalInstrument(name, year, type)
{this->stringCount = stringCount;}

Guitar::~Guitar() {cout <<"Guitar destroyed."<< endl;}
///Предефиниране на абстрактния метод:
void Guitar::printInfo()
{cout<<"Info: "<< getName() <<", "<< getYear() <<", "<< getType() <<", "<< getStringCount() <<"."<< endl;}

class Piano:public MusicalInstrument
{
private: int octaveCount;
public: Piano(){}; ~Piano();
        Piano(string, int, string, int);
        void printInfo();
        int getOctaveCount() {return octaveCount;}
};

Piano::Piano(string name, int year, string type, int octaveCount):MusicalInstrument(name, year, type)
{this->octaveCount = octaveCount;}

Piano::~Piano() {cout <<"Piano destroyed." << endl;}

void Piano::printInfo()
{cout<<"Info: "<< getName() <<", "<< getYear() <<", "<< getType() <<", "<< getOctaveCount() <<"."<< endl;}

int main()
{
///Абстрактен клас -> работим с масив от указатели и го пълним:
MusicalInstrument* instruments[3];
MusicalInstrument* firstInstrument = new Guitar("Garfield", 1997, "String", 6);
MusicalInstrument* secondInstrument = new Piano("PressPlay", 2000, "Key", 8);
MusicalInstrument* thirdInstrument = new Guitar("Wilson", 1980, "String", 7);
instruments[0] = firstInstrument;
instruments[1] = secondInstrument;
instruments[2] = thirdInstrument;
///Bubble Sort:
for(int i = 0; i < 2; i++)
{
for(int j = 0; j < 2; j++)
{
if(instruments[j]->getYear() > instruments[j+1]->getYear())
{
///Правило на змията:
MusicalInstrument* temporary = instruments[j];
instruments[j] = instruments[j+1];
instruments[j+1] = temporary;
}}}

for (int i = 0; i < 3; i++)
{instruments[i]->printInfo();}
return 0;
}
