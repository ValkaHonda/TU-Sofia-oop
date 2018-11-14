#include <iostream>

using namespace std;



class Animal{
private:
    static int age;
public:
    class Head{
    public:
        string name;
        void cutOffHead(){
            age++;
            cout << age << endl;
            cout << "The head is cut off " << endl;
        }
    };

    void doSomething(){
        Head currentHead;
        currentHead.name = "abcabc";
        cout << currentHead.name;
    }
};
int Animal::age = 10;

int main()
{



    Animal::Head h1;
    h1.name = "honda";
    cout << h1.name << endl;
    cout << h1.name << endl;
    h1.cutOffHead();


    return 0;
}
