// 
// main.cpp
//  Hard Recursion Solution
// 
//  Created by Charles Bucher on 1/25/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

/*
   Problem 1
   Create a file using ifstream, write anything you want to it, and then open 
   that same file using ofstream, and read what you just wrote to it. Clear the 
   file when you are done with it.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    const char * filename = "myNewFile.txt";
    
    // 1. Write to the file
    ofstream outFile;
    outFile.open(filename);
    // Can also do ofstream outFile(filename);
    
    //Write to file
    if(outFile.is_open())
    {
        for(int i = 1; i <= 10; i++)
        {
            outFile << i << "^2 = " << i * i << endl;
        }
    }
    else
    {
        cerr << "There was a problem opening the file to write!\n";
    }
    
    outFile.close();
    
    // 2. Read from the file
    ifstream inFile;
    inFile.open(filename);
    // Can also do ifstream inFile(filename);
    
    if(inFile.is_open())
    {
        string line;
        while(getline(inFile, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cerr << "There was a problem opening the file to read!\n";
    }
    
    inFile.close();
    
    // 3. Clear the file
    outFile.open(filename);
    outFile.close();
    
    return 0;
}
