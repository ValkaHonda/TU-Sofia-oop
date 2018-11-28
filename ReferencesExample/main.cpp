#include <iostream>

using namespace std;



void printNumber(int& numb){
    cout << numb << endl;
    numb = 18;
}


void swapVersion2(int& a, int& b){
    int c;
    c = a;
    a = b;
    b = c;
}

int main()
{

    int numb1 = 3;
    int& numb2 = numb1;
    int& numb3 = numb1;

    numb2 = 4;
    numb3 = 6;

    cout<<numb1<<endl<<numb2<<endl<<numb3<<endl;


    cout<<&numb1<<endl<<&numb2<<endl<<&numb3<<endl;


    int a = 2, b = 10;
    cout<<a<<endl<<b<<endl;
    swapVersion2(a,b);
    cout<<a<<endl<<b<<endl;

    return 0;
}
