#include<bits/stdc++.h>

using namespace std;

class Box{
    int length, breadth, height;

    public:  // this is very important
    // default constructor
    Box(): length(0), breadth(0), height(0){}

    // parameterized constructor
    Box(int l, int b, int h): length(l), breadth(b), height(h){}

    // copy constructor
    Box(const Box& b)
    {
        length = b.length;
        breadth = b.breadth;
        height = b.height;
    }

    int getLength(){return length;}
    int getBreadth(){return breadth;}
    int getHeight(){return height;}
    long long CalculateVolume(){return (long long) length*breadth*height;}

    // overload the operator <
    bool operator<(Box &b)
    {
        if (this->length<b.length || this->breadth<b.breadth && this->length==b.length || this->height<b.height && this->breadth==b.breadth && this->length==b.length)
        {return true;}
        else
            return false;
    }

    friend ostream& operator<<(ostream &out, const Box &b);

};
    ostream& operator<<(ostream  &out, const Box &b){
         out<< b.length<<" "<< b.breadth<< " " << b.height;
         return out;
    }
