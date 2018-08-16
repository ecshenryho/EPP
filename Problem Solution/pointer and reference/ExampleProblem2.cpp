//
//  ExampleProblem1.cpp
//  PointersReferencesTutorial
//
//  Created by Charles Bucher on 8/15/17.
//  Copyright © 2017 Charles Bucher. All rights reserved.
//

/*
     Problem: Create a linked list, using the node struct to mimick the
     data below:
     
     Index:  Data
     0       2  -> 7
     1       3
     2       0 -> 5
     3       null
     4       9
     5       1
     
     Print out the data to the screen in the following format:
 
     2 7
     3
     0 5
     
     9
     1
 */

#include <iostream>
using std::cout;
using std::endl;

// Node data structure (given)
struct Node {
public:
    int data;
    Node * next;
};

// Print function (given)
void print(Node *);

int main()
{

    Node * edges[6] = {nullptr}; // Array of pointers to Nodes
    Node edgesCol1[6]; //First row of actual Nodes (pointers must point to real Nodes!
    Node edgesCol2[6]; //Second row of actual Nodes
    
    edges[0] = & edgesCol1[0]; // Assign the first pointer in our pointer array
                               // to the corresponding actual Node in the first
                               // column Node array
    
    edges[0]->data = 2; // Set value
    edges[0]->next = &edgesCol2[0]; // Assign the 'next' pointer of the first
                                    // column to the corresponding actual node
                                    // in the second column Node array. This is
                                    // done from the pointer array
    
    edges[0]->next->data = 7; //set value
    edges[0]->next->next = nullptr; // Assign the 'next' pointer of the second
                                    // column to null, as th
    
    //same logic for other array pointers below.
    edges[1] = &edgesCol1[1];
    edges[1]->data = 3;
    edges[1]->next = nullptr;
    
    edges[2] = &edgesCol1[2];
    edges[2]->data = 0;
    edges[2]->next = &edgesCol2[2];
    edges[2]->next->data = 5;
    edges[2]->next->next = nullptr;
    
    //edges[3] points to null
    
    edges[4] = &edgesCol1[3];
    edges[4]->data = 9;
    edges[4]->next = nullptr;
    
    
    edges[5] = &edgesCol1[4];
    edges[5]->data = 1;
    edges[5]->next = nullptr;
    
    for (int i = 0; i < 5; i++)
    {
        print(edges[i]);
    }
    
    return 0;
}

void print(Node * ptr)
{
    // Print nothing if the pointer is NULL
    if (ptr != nullptr)
    {
        // Show the first value since we know it's not null
        cout << ptr->data << " ";
        
        //Print again only if pointer's 'next' is not null
        if (ptr->next != nullptr)
        {
            //Show the second value since we know it's not null
            cout << ptr->next->data << " ";
        }
    }
    cout << endl;
}
