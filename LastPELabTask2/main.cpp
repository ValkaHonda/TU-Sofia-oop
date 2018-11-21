#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
/*
2ра задача от последното упражнение по ПЕ
Клас точка с член променливи
-> х
-> y
Конструктор с параметри и други функции ако са необходими.
Имаме клас окръжност, който наследява точка,
Има член променлива
-> радиус
Има конструктор с параметри и други функции, ако са необходими.
В главната функция имаме масив от обекти от клас окръжност.
И да се изведе онази окръжност, която има най-голям радиус.
*/

class Point{
private:
    int x;
    int y;
public:
    Point(int, int);
    Point(){}
    int getX(){
        return x;
    }
     int getY(){
        return y;
    }
};

Point::Point(int x, int y){
    this -> x = x;
    this -> y = y;
}

class Circle:public Point{
private:
    int radius;
public:
    Circle(int, int, int); ///Very Important -> We give radius + the properties from the parent class.
    Circle(){}
    int getR(){
        return radius;
    }
};

Circle::Circle(int radius, int x, int y):Point(x,y){
    this -> radius = radius;
}
int main()
{
    Circle circle1(6,2,3);
    Circle circle2(4,2,9);
    Circle circle3(5,1,3);
    Circle circle4(7,1,3);
    Circle circle5(20,1,3);
    Circle circle6(13,1,3);
    Circle circle7(79,1,3);


    vector<Circle> arr;
    arr.push_back(circle1);
    arr.push_back(circle2);
    arr.push_back(circle3);
    arr.push_back(circle4);
    arr.push_back(circle5);
    arr.push_back(circle6);
    arr.push_back(circle7);

    for(unsigned int i = 0; i < arr.size(); i++){
        for(unsigned int j = 0; j < arr.size() - 1; j++){
           if(arr[j].getR() > arr[j+1].getR()){
                Circle temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
           }
        }
    }

    cout<<"Coordinates of the circle with max radius: "<<endl;
    Circle lastObject = arr[arr.size() - 1];
    printf("(%d, %d)  radius -> %d\n", lastObject.getX(), lastObject.getY(), lastObject.getR());

    return 0;
}
