/*
AFFINE CIPHER
*/

#include "header.h"

//Function to calculate modulus of negative number with respect to positive number
int modNeg(int n, int m)
{
	n *= -1;
	
	int i = 1;
	
	do
	{
		m *= i;
		
		if (m >= n)
			break;
	} while (m < n);
	
	return m - n;
}
 //Calculate Greatest Common Divisor of two numbers
int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 
	
	return gcd(b, a % b);  
} 

//Calculate modular inverse of a with respect to m
int modularInverse(int a, int m) 
{ 
	a = a%m; 
	
	for (int x = 1; x < m; ++x) 
	{
		if ((a*x) % m == 1) 
	 		return x;
	} 
} 
