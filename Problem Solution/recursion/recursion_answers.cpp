//
// recursion_answers.cpp
// Hard Recursion Solution
//
// Created by Charles Bucher on 1/25/17.
// Copyright © 2017 Charles Bucher. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

// Prototypes
int power(int, int);
int evens(int, int *, int);
int pyramid(int);
int count7(int);
bool groupWith6(int, int *, int, int);

int main()
{
    
    // powers Test
    cout << "powers Test\n";
    cout << power(2, 4) << endl; // 16
    cout << power(3, 3) << endl; // 27
    cout << power(4, 5) << endl; // 1024
    
    // evens Test
    cout << "\nevens Test\n";
    int evensArray1[4] = {1, 5, 3, 7};
    int evensArray2[5] = {2, 4, 6, 8, 2};
    int evensArray3[4] = {1, 2, 3, 4};
    cout << evens(0, evensArray1, 4) << endl; // 0
    cout << evens(0, evensArray2, 5) << endl; // 5
    cout << evens(0, evensArray3, 4) << endl; // 2
    
    // pyramid Test
    cout << "\npyramid Test\n";
    cout << pyramid(4) << endl; // 10
    cout << pyramid(7) << endl; // 28
    cout << pyramid(15) << endl; // 120
    
    // count7 Test
    cout << "\ncount7 Test\n";
    cout << count7(67780197) << endl; // 3
    cout << count7(345207) << endl; // 1
    cout << count7(77777) << endl; // 5
    
    // groupWith6 Test
    cout << "\ngroupWith6 Test\n";
    int group6Array[4] = {6, 5, 10, 4};
    cout << groupWith6(0, group6Array, 12, 4) << endl; // False
    cout << groupWith6(0, group6Array, 15, 4) << endl; // True (6+5+4 = 15)
    cout << groupWith6(0, group6Array, 8, 4) << endl; // False
    
    return 0;
}

int power(int base, int exp)
{
    // Base Case
    if(exp == 0)
    {
        return 1; // Anything raised to the 0 power is 1
    }
    // Recursive Case
    else
    {
        // Muliplty by base and move exponent closer to zero
        return power(base, exp - 1) * base;
    }
}

int evens(int index, int * nums, int size)
{
    // Base case - we are done walking through the array
    if(index >= size)
    {
        return 0;
    }
    // Recursive case - more elements to go!
    else
    {
        int add = 0;
        if(nums[index] % 2 == 0) // Check if value is even
        {
            add = 1;
        }
        
        /*
         Increment running total and take the next step through the array.
         Figured it if current value was even, and then passes the rest of
         the array to "someone else" to solve
         */
        return evens(index + 1, nums, size) + add;
    }
}

int pyramid(int layers)
{
    // Base case - we are at the top layer which is 1 brick
    if(layers == 1)
    {
        return 1;
    }
    // Recursive case - add current layer values and calculate the number of
    // bricks for the rest of the pyramid
    else
    {
        return layers + pyramid(layers - 1);
    }
    
}

int count7(int number)
{
    // Check far right digit and see if 7
    int add = 0;
    if(number % 10 == 7)
    {
        add = 1;
    }
    
    // Base case - the number passed in is one digit
    if(number <= 9)
    {
        return add; // If number is 7, add 1
    }
    // Recursive case - number is multiple digits
    else
    {
        // Increment total if number was 7, and then pass in a number with the
        // digit that we just check removed.
        return count7(number / 10) + add;
    }
}

// Walkthrough the array by incrementing start value for each recursive call
// Try to find some some way that will bring target to 0.

bool groupWith6(int index, int * nums, int target, int size)
{
    // Base Case - we have finished walking through the array
    if(index >= size)
    {
        if(target == 0) // If target was brought to zero, we found a set!
        {
            return true;
        }
        else // No group within array adds to target
        {
            return false;
        }
    }
    // Recursive case - still more array elements to go.
    else
    {
        // The number we are on is 6. Must subtract from the target value
        if(nums[index] == 6)
        {
            return groupWith6(index + 1, nums, target - 6, size);
        }
        else
        {
            /*
             Subtract current value from the target and don't. This allows
             us to test this value as if it was in the set and also not.
             This is accomplished by using an "or" statement to test both
             cases. If one of them brings the target to 0, then this number
             must be one of th numbers in the valid set.
             */
            return groupWith6(index + 1, nums, target - nums[index], size) ||
            groupWith6(index + 1, nums, target, size);
        }
        
    }
}
