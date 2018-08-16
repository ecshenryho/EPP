// 
// main.cpp
//  Hard Recursion Solution
// 
//  Created by Charles Bucher on 1/25/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

/*
 Problem 3
 Create (outside of a .cpp file), a text file with at least 4 lines of
 random text. Modify each odd numbered line at the beginning with “I am odd ”
 and each even numbered line at the beginning with “I am not ”.
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    const char * filename = "randomText.txt"; // File we are working with
    const char * filename_copy = "randomText_copy.txt"; // Temp file
    
    ifstream original(filename);
    ofstream copy(filename_copy);
    
    copy << original.rdbuf(); // Copy original file into temp file
    
    original.close(); // Close - will reopen as ofstream (writing)
    copy.close(); // Close - will reopen as ifstream (reading)
    
    // Now that we have copy file, we can edit the original
    ofstream writeFile(filename); // Original
    ifstream readFile(filename_copy); // Copy

    string curr_line;
    int line_num = 1;
    while(getline(readFile, curr_line))
    {
        // Determine line to write to original file by combining new text with
        // line from the copy
        string text_to_add = (line_num++ % 2 == 1) ? "I am odd " : "I am not ";
        // Add line to original file
        writeFile << text_to_add << curr_line << endl;
    }
    
    // Cleanup
    readFile.close();
    writeFile.close();
    remove(filename_copy); // Remove temp file
    
    return 0;

}
