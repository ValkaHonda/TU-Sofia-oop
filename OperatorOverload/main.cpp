#include <iostream>
#include <string.h>

using namespace std;


class MathVector{
private:
    int x;
    int y;
public:
    MathVector(){}
    MathVector(int, int);
    ~MathVector();
    friend ostream& operator<<(ostream&, const MathVector&);
    MathVector operator+(const MathVector&);
    MathVector operator-(const MathVector&);
    MathVector& operator-();
    MathVector& operator!();
    bool operator==(const MathVector&);
    bool operator<(const MathVector&);
    MathVector& operator=(const MathVector&);
};

MathVector::MathVector(int x, int y){
    this -> x = x;
    this -> y = y;
}

MathVector::~MathVector(){
    cout<<"MathVector disappear"<<endl;
}

ostream& operator<<(ostream& stream, const MathVector& matrix){
    stream<<matrix.x<<" "<<matrix.y<<endl;
    return stream;
}

 MathVector MathVector::operator+(const MathVector& matrix){
    MathVector result;
    result.x = this -> x + matrix.x;
    result.y = this -> y + matrix.y;
    return result;
 }

 MathVector MathVector::operator-(const MathVector& matrix){
    MathVector result;
    result.x = this -> x - matrix.x;
    result.y = this -> y - matrix.y;
    return result;
 }

 MathVector& MathVector::operator-(){
    this -> x = -x;
    this -> y = -y;
    return *this;
 }

MathVector& MathVector::operator!(){
    this -> x = -x;
    this -> y = -y;
    return *this;
 }

bool MathVector::operator==(const MathVector& matrix){
    if(this -> x == matrix.x && this -> y == matrix.y){
        return true;
    }
    return false;
}

bool MathVector::operator<(const MathVector& matrix){
    if(this -> x < matrix.x){
        return true;
    }
    return false;
}

MathVector& MathVector::operator=(const MathVector& matrix){
    this -> x = matrix.x;
    this -> y = matrix.y;
    return *this;
}

class Hero{
private:
    char* name;
public:
    Hero(){}
    Hero(char*);
    ~Hero();
    Hero& operator=(const Hero&);
    friend ostream& operator<<(ostream&, const Hero&);
};

Hero::Hero(char* name){
    int textSize = strlen(name);
    this -> name = new char [textSize + 1];
    strcpy(this -> name, name);
}

Hero::~Hero(){
    cout<<"Hero died"<<endl;
    delete []name;
}

Hero& Hero::operator=(const Hero& hero){
    int textSize = strlen(hero.name);
    if(this -> name != NULL){
        delete []this -> name;
    }
    this -> name = new char [textSize + 1];
    strcpy(this -> name, hero.name);
    return *this;
}

ostream& operator<<(ostream& stream,const Hero& hero){
    for(unsigned int i = 0; i < strlen(hero.name); i++){
        stream<<hero.name[i];
    }
    stream<<endl;
    return stream;
}

int main()
{
    MathVector matrix1(10, 20);
    MathVector matrix100(10, 20);
    MathVector matrix1000(10, 20);
    MathVector matrix2(15, 20);
    MathVector matrix200(150, 200);
    MathVector matrix2000(200, 200);
    MathVector matrix3 = matrix1 + matrix2;
    MathVector matrix4 = matrix1 - matrix2;
    -matrix1;
    !matrix2;
    bool equal = matrix1==matrix2;
    equal = matrix100==matrix1000;
    bool isGreater = matrix200 < matrix2000;
    matrix4 = matrix200;


    cout<<matrix1;
    cout<<matrix2;
    cout<<matrix3;
    cout<<matrix4;
    cout<<equal<<endl;
    cout<<isGreater<<endl;

    char arr[100];
    arr[0] = 'n';
    arr[1] = 'o';
    arr[2] = 'w';
    arr[3] = '\0';

    Hero hero(arr);

    char arr1[100];
    arr1[0] = 'n';
    arr1[1] = 'u';
    arr1[2] = 'l';
    arr1[3] = '\0';
    Hero hero1(arr1);

    cout<<hero;
    cout<<hero1;

    hero = hero1;
    cout<<endl;
    cout<<hero;
    cout<<hero1;
    return 0;
}
