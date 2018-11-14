#include <iostream>

using namespace std;



class Animal{
public:
    int age;
    class Head{
    public:
        string name;
    };

    void doSomething(){
        Head currentHead;
        currentHead.name = "abcabc";
        cout << currentHead.name;
    }
};


int main()
{

    Animal::Head h1;
    h1.name = "honda";
    cout << h1.name << endl;


    return 0;
}
