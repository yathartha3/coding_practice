/*

A simple tutorial to initialize base class members from child class constructor.

*/
#include <stdio.h>
#include <iostream>

using namespace std;

class Vehicle
{
private:
//    int year;
//    string name;
public:
    int year{};
    string name{""};
    Vehicle(int y, string n) : year(y), name(n)
    {};
    Vehicle(){};
};
class Car : public Vehicle
{
public:
    int wheels;
    string model;
    Car(int y, int w, string n, string m): Vehicle(y, n), wheels(w), model(m)  // Important to remember
    {};
};
int main()
{
    Car ford(1964, 4 , "Carla" , "mustang");
    cout<<ford.year<<endl;
    cout<<ford.name<<endl;
    cout<<ford.model<<endl;
    cout<<ford.wheels<<endl;
}
