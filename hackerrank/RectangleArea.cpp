#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
 class Rectangle
 {
     protected:
     int width{0};
     int height{0};

    public:
     void display();
 };

 class RectangleArea : public Rectangle
 {
     public:
     void read_input();
     void display(); //overloaded
 };

 void Rectangle::display()
 {
     cout<<width<<" "<<height<<endl;
 }

 void RectangleArea::display()
 {
     cout<<width*height<<endl;
 }

 void RectangleArea::read_input()
 {
     cin>>width>>height;
 }


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}

