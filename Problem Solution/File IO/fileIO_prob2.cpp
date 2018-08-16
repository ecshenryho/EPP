// 
// main.cpp
//  Hard Recursion Solution
// 
//  Created by Charles Bucher on 1/25/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

/*
 Problem 2
 Create (outside of a .cpp file), a file with a sequence of 5 numbers.
 Create 5 int variables, open the file, and assign those variables to the
 numbers within the file. Finally, change the values of those variables, and
 then override the values originally within the file with the new values.
 
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    const int ARR_SIZE = 5;
    const char * filename = "numbers.txt";
    int val[ARR_SIZE] = {0};
    
    ifstream inFile(filename);
    // Can also do inFile.open(filename);
    
    if(inFile.is_open())
    {
        string get_val;
        for(int i = 0; i < ARR_SIZE; i++)
        {
            inFile >> get_val;
            val[i] = stoi(get_val); // Convert string to int
            
        }
    }
    
    for(int i = 0; i < ARR_SIZE; i++)
    {
        cout << val[i] << endl;
        val[i] += val[i] / 2;
        
    }
    
    inFile.close();
    
    ofstream outFile(filename);
    if(outFile.is_open())
    {
        for(int i = 0; i < ARR_SIZE; i++)
        {
            outFile << val[i] << endl;
            
        }
    }
    
    outFile.close();
    
    return 0;
}
