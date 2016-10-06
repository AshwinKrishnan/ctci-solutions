/*
 * Solutions to Cracking the Coding Interview Edition 4
 *
 * By: Ashwin Krishnan
 * 
 * Problem 1.1
 * ------------
 * Implement an algorithm to determine if an array has all unique elements
 * What if you can not use additional data structures?
 */

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool isAllUnique(int* array, int size);

int main()
{
    int test[5] = {1, 3, 9, 6, 4};
    int* t = test;

    int size = sizeof(test)/sizeof(int);

    //Testing function
    cout << "Size of Array: " << size << endl; 
    cout << "\nOutput: " << isAllUnique(test, size) << endl;

    return 0;
}

/*
 *Runtime Analysis - O(n)
 *Space Complexity - O(n)
 */

bool isAllUnique(int* array, int size)
{
    int temp = 0;

    for(int i = 0; i < size; i++)
    {
       temp = array[i]; 
      
       if(i == size - 1)
       {
           return true;
       }

       if(temp == array[i + 1])
       {
           return false;
       } 

    }

    return true;
}