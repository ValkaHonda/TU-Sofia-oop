#include <iostream>
using namespace std;

class Car
{
private: int maxSpeed; string colour;
public: Car(){}; ~Car();
        Car(int, string);
        friend string compareSpeed(Car obj1, Car obj2);
};
Car::Car(int maxSpeed, string colour)
{this->maxSpeed = maxSpeed; this->colour = colour;}
Car::~Car() {cout <<"Car destroyed."<< endl;}


string compareSpeed(Car obj1, Car obj2)
{if (obj1.maxSpeed > obj2.maxSpeed)
{return obj1.colour;} else {return obj2.colour;}
}

class Song
{
private: string title; int year;
public: Song(){}; ~Song();
void setYear(int year) {this->year = year;};
        Song(string, int);
friend string checkSong(Song &song);
};
Song::Song(string title, int year) {this->title = title; this->year = year;}
Song::~Song() {cout <<"Song destroyed!"<<endl;}

string checkSong(Song &song)
{if(song.year >= 1980 && song.year <= 1989) {return "Good period.";}
else {return "Oh, well.";}}

class Cake
{
private: string name; int price;
public: Cake(){}; ~Cake();
        Cake(string, int);
friend void compareCakes(Cake firstCake, Cake secondCake);
};

Cake::Cake(string name, int price) {this->name = name; this->price = price;}
Cake::~Cake() {cout <<"Cake eaten!"<< endl;}
void compareCakes(Cake firstCake, Cake secondCake)
{if(firstCake.price > secondCake.price)
{cout << firstCake.name << endl;} else {cout << secondCake.name << endl;}
}

class Bag;

class Person
{
private: string name;
public: Person(){}; ~Person();
        Person(string);
void printBackPack(Bag);
};

Person::Person(string name) {this->name = name;}
Person::~Person() {cout <<"Person killed!"<< endl;}
/*void Person::printBackPack(const Bag& bag)
{cout << bag.price << endl;}*/

class Bag
{
private: double price;
public: Bag(){}; ~Bag();
        Bag(double);
        friend void Person::printBackPack(Bag);
};
void Person::printBackPack(Bag bag)
{cout << bag.price << endl;}

Bag::Bag(double price) {this->price = price;}
Bag::~Bag() {cout <<"Bag destroyed!"<< endl;}



int main()
{
Cake cake1("Fruit", 200);
Cake cake2("Sacher", 300);
//compareCakes(cake1, cake2);

/*Car car1(220, "black");
Car car2(180, "red");
string result = compareSpeed(car1, car2);
cout << result << endl;*/


/*Song firstSong("Spring", 1985);
Song secondSong("Bleeding Love", 2000);
Song thirdSong("Switch", 2013);
Song songs[3];
songs[0] = firstSong; ///songs[0] uses a copy of the first song (not the real object).
songs[1] = secondSong;
songs[2] = thirdSong;

for (int i = 0; i < 3; i++)
{cout<< checkSong(songs[i])<< endl;}

cout << "------------"<< endl;
songs[0].setYear(1950);
cout << checkSong(songs[0]) << endl;
cout<< checkSong(firstSong) << endl;*/
return 0;
}


