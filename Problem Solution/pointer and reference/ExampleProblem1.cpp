//
//  ExampleProblem2.cpp
//  PointersReferencesTutorial
//
//  Created by Charles Bucher on 8/15/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

/*
 Problem: Create a simple class of you choosing. Within main, create an array of
          pointers to your class. Initiliaze and add data using the array of
          pointers. Demonstrate knowledge of the different ways to dereference 
          pointers.
 */

#include <iostream>
using std::cout;
using std::endl;

class SillyClass
{
private:
    int _a;
    
public:
    SillyClass()
    {
        _a = 0;
    }
    ~SillyClass() = default;
    
    void setA(int a)
    {
        _a = a;
    }
    int getA()
    {
        return _a;
    }
};

int main()
{
    SillyClass * myArray[2];
    
    // Using one method of de-referencing
    cout <<(*myArray[0]).getA() << endl; // Will print '0'
    (*myArray[0]).setA(3);
    cout << (*myArray[0]).getA() << endl; // Will print '0'
    
    // Using another method of de-referencing
    cout <<(*myArray[1]).getA() << endl; // Will print '1'
    myArray[1]->setA(4);
    cout << myArray[1]->getA() << endl; // Will print '1'
    
    
    
    
    return 0;
}
