#include <iostream>
using namespace std;

class MathVector
{
private: int x, y;
public:
    MathVector(){}; ~MathVector();
    MathVector(int, int);
    MathVector operator+(const MathVector& otherVector);
    MathVector operator-(const MathVector& otherVector);
    bool operator==(const MathVector& otherVector);
    friend ostream& operator<<(ostream& stream, const MathVector& otherVector);

    int getX() {return x;}
    int getY() {return y;}
};

MathVector::MathVector(int x, int y) {this->x = x; this->y = y;}
MathVector::~MathVector(){cout <<"Destructing object."<< endl;}
///+ Override:
MathVector MathVector::operator+(const MathVector& otherVector)
{
    MathVector result;
    result.x = this->x + otherVector.x;
    result.y = this->y + otherVector.y;
    return result;
}

MathVector MathVector::operator-(const MathVector& otherVector)
{
MathVector result;
result.x = this->x - otherVector.x;
result.y = this->y - otherVector.y;
return result;
}

bool MathVector::operator==(const MathVector& otherVector)
{
if ((this->x == otherVector.x) && (this->y = otherVector.y))
     {return 1;}
else {return 0;}
}

ostream& operator<<(ostream& stream, const MathVector& otherVector)
{
stream <<"X: "<< otherVector.x <<" and "<<"Y: "<< otherVector.y << endl;
return stream;
}

class Anime
{
private: string name; int year;
public: Anime(){}; ~Anime();
        Anime(const Anime&);
        Anime(string, int);
        Anime& operator=(const Anime& otherAnime);
friend ostream& operator<<(ostream& stream, const Anime& anime);
};

Anime::Anime(const Anime& oldAnime)
{this->name = oldAnime.name; this->year = oldAnime.year;}



Anime::Anime(string name, int year)
{this->name = name; this->year = year;}
Anime::~Anime() {cout <<"Anime destroyed." << endl;}


ostream& operator<<(ostream& stream, const Anime& anime)
{
stream << anime.name <<" and "<<anime.year << endl;
return stream;
}

Anime& Anime::operator=(const Anime& otherAnime)
{
this->name = otherAnime.name;
this->year = otherAnime.year;
return *this;
}

class Cake
{
private: string name; double price;
public: Cake(){}; ~Cake();
        Cake(const Cake&);
        Cake(string, double);
        Cake& operator=(const Cake& oldCake);
friend ostream& operator<<(ostream& stream, const Cake& cake);
};

Cake::Cake(const Cake& oldCake)
{this->name = oldCake.name; this->price = oldCake.price;}

Cake::Cake(string name, double price)
{this->name = name; this->price = price;}

Cake& Cake::operator=(const Cake& oldCake)
{
this->name = oldCake.name;
this->price = oldCake.price;
return *this;
}

Cake::~Cake(){cout <<"Cake eaten."<< endl;}
ostream& operator<<(ostream& stream, const Cake& cake)
{
stream << cake.name <<" and "<< cake.price << endl;
return stream;
}

int main()
{
MathVector firstVector(10, 20);
MathVector secondVector(100, 200);
MathVector resultVector = firstVector + secondVector;
cout << resultVector.getX() <<" and "<< resultVector.getY() << endl;

resultVector = secondVector - firstVector;
cout << resultVector.getX() <<" and "<< resultVector.getY() << endl;

MathVector vector1(2, 4);
MathVector vector2(10, 10);
MathVector result2 = vector1 + vector2;
cout << "Addition 2:"<< endl;
cout << vector1.getX() <<" and "<< vector1.getY() << endl;
cout << result2.getX() <<" and "<< result2.getY() << endl;
cout << "Comparison:"<< endl;
cout << (vector1 == vector2) << endl;
cout << "<< Overload:"<< endl;
Anime firstAnime("Akira", 1988);
cout << firstAnime << endl;
Cake firstCake("Saher", 30);
cout << firstCake << endl;
cout << vector2 << endl;
Anime secondAnime("Yami Shibai", 2013);
Anime thirdAnime("Shaman King", 2005);
cout <<"= Overload:" << endl;
secondAnime = thirdAnime;
cout << secondAnime <<"and "<< thirdAnime << endl;
return 0;
}
