/*
AFFINE CIPHER
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

bool checkKey (int, int);
bool relativePrime (int, int);
int gcd(int, int);
string encrypt (int, int, string);
string decrypt (int, int, string);
int modularInverse(int, int); 
int modNeg(int, int);

const int GLOBAL_CONST_Z = 26;

