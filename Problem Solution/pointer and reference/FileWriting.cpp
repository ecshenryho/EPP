//
//  main.cpp
//  FileWriting
//
//  Created by Charles Bucher on 1/25/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    
    ifstream inFile;
    ofstream outFile, dupFile;
    
    outFile.open("newFile.txt");
    
    while(outFile.is_open()) {
        for(int i = 1; i <= 100; i++) {
            outFile << i << " * 2 = " << i * 2 << endl;
        }
        break;
    }
    
    outFile.close();
    
    
    inFile.open("newFile.txt");
    dupFile.open("dupFile.txt");
    string line;

    while(!inFile.eof() && dupFile.is_open()) {
        getline(inFile, line);
        dupFile << line << endl;
    }
    
    inFile.close();
    dupFile.close();
    
    return 0;
}
