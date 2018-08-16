//
//  main.cpp
//  ClassesTest
//
//  Created by Charles Bucher on 6/1/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

//
//  ClassesInheritance.cpp
//  TestIO
//
//  Created by Charles Bucher on 5/31/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

/*
   Create a class called rectangle. Make all members private and create
   getter/setter methods for those members. Create any members/methods for 
   the class you think would pertain or be useful to a rectangle object.
 
   Create two constructors for the class - one with default values given to
   the members, another with parameters used to set the member values.
   Implement both types.
 
   Make a private static member called number_of_rectangles. Adjust the
   constructors accordingly so that whenever an instance is
   created/destroyed, the static member is changed. Create a getter for this
   static member (no setters!).
 
   Create a private member that is dynamically allocated. Change the 
   destructor accordingly so that the memory is properly released when the
   instance is destroyed

   Create a class called square. Instead of copying all of rectangle’s code,
   make square a child class of rectangle.

   Implement within a main() function
*/

#include <iostream>
#include <string>
using namespace std;

// Rectangle class
class Rectangle
{
protected:
    static int numOfRectangles;
    static int incrementalID;
    int width;
    int height;
    int * rectangleID; // To be dynamically allocated

public:
    
    // Specific constructor
    Rectangle(int width, int height) : width(width), height(height)
    {
        rectangleID = new int;
        *rectangleID = ++incrementalID; // Incremental ID
        numOfRectangles++;
    }
    
    // Default constructor
    Rectangle()
    {
        rectangleID = new int;
        *rectangleID = ++incrementalID; // Incremental ID
        numOfRectangles++;
        width = 1;
        height = 1;
    }
    
    // Destructor
    ~Rectangle()
    {
        delete rectangleID;
        numOfRectangles--;
    }
    
    // Width Setter
    void setWidth(int newWidth)
    {
        width = newWidth;
    }
    
    // Width Getter
    int getWidth()
    {
        return width;
    }
    
    // Height Setter
    void setHeight(int newHeight)
    {
        height = newHeight;
    }
    
    // Height Getter
    int getHeight()
    {
        return height;
    }
    
    static int getNumOfRectangles()
    {
        return numOfRectangles;
    }
    
    int getRectangleID()
    {
        return *rectangleID;
    }
    
    // Calculate rectangle's area
    int getArea()
    {
        return width * height;
    }
};

class Square: public Rectangle
{
public:
    Square(int side): Rectangle(side, side) {}
    
    Square(): Rectangle() {} // Default constructor
    
    void setHeight(int newHeight) // Height must equal width
    {
        width = newHeight;
        height = newHeight;
    }
    
    void setWidth(int newWidth) // Height must equal width
    {
        width = newWidth;
        height = newWidth;
    }

};

int Rectangle::numOfRectangles = 0; // Initialize static member
int Rectangle::incrementalID = 0; // Initialize static member


int main()
{
    Rectangle * rectangle1 = new Rectangle(); // Default rectangle constructor
    Rectangle * rectangle2 = new Rectangle(5, 6);
    Rectangle * rectangle3 = new Rectangle(2, 4);
    Square * square1 = new Square(); // Default square constructor
    Square * square2 = new Square(3);
    
    cout << "Rectangle " << rectangle1->getRectangleID() << " area is: ";
    cout << rectangle1->getArea() << endl;
    
    cout << "Rectangle " << rectangle2->getRectangleID() << " area is: ";
    cout << rectangle2->getArea() << endl;
    
    cout << "Rectangle " << rectangle3->getRectangleID() << " area is: ";
    cout << rectangle3->getArea() << endl;
    
    cout << "Rectangle " << square1->getRectangleID() << " area is: ";
    cout << square1->getArea() << endl;
    
    cout << "Rectangle " << square2->getRectangleID() << " area is: ";
    cout << square2->getArea() << endl;
    
    // Demonstrate how delete an instance of the class will decrement the total
    // number of rectangles, a static, class-wide variable.
    
    cout << "\nThere are " << rectangle1->getNumOfRectangles() << " rectangles\n";
    delete rectangle3;
    delete square1;
    cout << "There are " << rectangle1->getNumOfRectangles() << " rectangles\n";
    
    // Demonstrate getters and setters
    rectangle1->setHeight(10);
    rectangle1->setWidth(4);
    cout << "\nRectangle " << rectangle2->getRectangleID() << " area is: ";
    cout << rectangle2->getArea() << endl;
    
    square1->setHeight(11);
    cout << "Rectangle " << square2->getRectangleID() << " area is: ";
    cout << square2->getArea() << endl << endl;
    
    Square * square3 = new Square(20); // Note the incremental ID
    cout << "Rectangle " << square3->getRectangleID() << " area is: ";
    cout << square3->getArea() << endl << endl;
    
    
    
    
    return 0;
}
