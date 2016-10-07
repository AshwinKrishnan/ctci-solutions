/*
 * Solutions to Cracking the Coding Interview Edition 4
 *
 * By: Ashwin Krishnan
 * 
 * Problem 5.5
 * ------------
 * Write a function to determine the number of bits required to convert an 
 * integer A to integer B
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

//XOR gives us the bits that are different => A = 0001, B = 1010
//A xor B = 1011 (counting the number of 1's in the result we
//get the required number of bits to change A to B)
int bits_required(int A, int B)
{
	int XOR = A ^ B;				//Compute XOR to get bit difference
	int binary_form;
	unsigned int checker = 1 << 31; //Bit shifting to get 2^31 (used as mask)
	int count = 0;

	if(A < 0 || B < 0)
	{
		cout << "Error: Only supports unsigned integers" << endl;

		exit(0);
	}

	for(int i = 0; i < 32; i++)
	{
		int temp = XOR & checker;

		if(temp != 0)
		{
			count = count + 1;
		}
		
		checker = checker >> 1;
		
	}
	
	
	return count;
	
			
}

int main()
{
	//Testing implementation
	unsigned int A = 0;
	unsigned int B = 1;
	
	cout << "#Bits to convert " << A << " -> " << B << " = " << bits_required(A,B) <<  endl;
	
	A = 2;
	B = 8;
	
	cout << "#Bits to convert " << A << " -> " << B << " = " << bits_required(A,B) <<  endl;
	
	A = 31;
	B = 14;
	
	cout << "#Bits to convert " << A << " -> " << B << " = " << bits_required(A,B) <<  endl;
	
	A = 0;
	B = -1000000000;
	
	cout << "#Bits to convert " << A << " -> " << B << " = " << bits_required(A,B) <<  endl;
	return 0;
}

