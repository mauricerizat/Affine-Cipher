/*
AFFINE CIPHER
*/

#include "header.h"

//Function to Decrypt Affine Cipher
string decrypt (int a, int b, string cipher)
{
	cout << "DECRYPTION" << endl;
	
	int aIn = modularInverse (a, GLOBAL_CONST_Z); //Stores modular inverse of a with respect to GLOBAL_CONST_Z
	
	string plain = ""; //Stores Plaintext
	
	for (int i = 0; i < cipher.length(); ++i) //Traverse ciphertext string
	{
		if (cipher[i] >= 65 && cipher[i] <= 90) //Decrypt uppercase characters
			plain += (aIn * modNeg(cipher[i] - 65 - b, GLOBAL_CONST_Z)) % GLOBAL_CONST_Z + 65;
		else if (cipher[i] >= 97 && cipher[i] <= 122) //Decrypt lowecase characters
			plain += (aIn * modNeg(cipher[i] - 97 - b, GLOBAL_CONST_Z)) % GLOBAL_CONST_Z + 97;
		else
			plain += cipher[i]; //Process other characters
	}	
	
	cout << "\nPlaintext:\n\n" << plain << endl; //Output plaintext
	
	return plain;
}
