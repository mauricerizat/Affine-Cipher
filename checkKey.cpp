/*
AFFINE CIPHER
*/

#include "header.h"

//Function to check validity of Key
bool checkKey (int a, int b)
{
	cout << "Checking Key: " << a << " " << b <<"\n" << endl;
	
	bool validity = true; //Flag for validity of key
	
	if (gcd(a, GLOBAL_CONST_Z) != 1) //Check if a is not a relative prime to GLOBAL_CONST_Z
	{
		//Error message
		cout << "\tValue of a is invalid. ";
		cout << "It must be an Integer relatively prime to " << GLOBAL_CONST_Z << endl;
		validity = false;
	}
	else if (a > GLOBAL_CONST_Z || a < 0) //Check is a is negative or greater than GLOBAL_CONST_Z
	{
		//Error message
		cout << "\tValue of a is invalid. ";
		cout << "It must be a positive Integer less than " << GLOBAL_CONST_Z << " for unique ciphertext" << endl;
		validity = false;
	}
	
	if (b < 0 || b >= GLOBAL_CONST_Z) //Check if b is between 0 and GLOBAL_CONST_Z
	{
		//Error message
		cout << "\tValue of b is invalid. It must be an Integer in the range 0 to " << GLOBAL_CONST_Z-1 << endl;
		validity = false;
	}
	
	if (a == 1 && b == 0) //Check if a and b are 1 and 0 respectively - Invalid key-pair
	{
		//Error message
		cout << "\tKey-pair (1, 0) cannot be used. It causes ciphertext to be identical to plaintext";		
		validity = false;
	}
	
	return validity;
}
