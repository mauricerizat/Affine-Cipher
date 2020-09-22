/*
AFFINE CIPHER
*/

#include "header.h"

//Function to Encrypt Affine Cipher
string encrypt (int a, int b, string plain)
{
	cout << "ENCRYPTION" << endl;
	
	string cipher = ""; //Stores Ciphertext
	
	for (int i = 0; i < plain.length(); ++i) //Traverse plaintext string
	{
		if (plain[i] >= 65 && plain[i] <= 90) //Encrypt uppercase characters
			cipher += ((plain[i]-65)*a + b) % GLOBAL_CONST_Z + 65;
		else if (plain[i] >= 97 && plain[i] <= 122) //Encrypt lowecase characters
			cipher += ((plain[i]-97)*a + b) % GLOBAL_CONST_Z + 97;
		else
			cipher += plain[i]; //Process other characters
	}	
	
	cout << "\nCiphertext:\n\n" << cipher << endl; //Output ciphertext
	
	return cipher;
}
