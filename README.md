# Affine-Cipher
A simple console-based C++ program that performs encryption and decryption based on the Affine Cipher. 

## IMPORTANT

THIS PROGRAM IS WRITTEN IN C++ (C++11 recommended)

THIS README DEMONSTRATES THE EXECUTION OF THIS PROGRAM ON A LINUX TERMINAL WITH A C++ COMPILER

## FILE IO

Please place all plaintext and ciphertext files to be processed in the "data" folder.

Make sure to include the extention of the file if required.

The output file will also be stored in the "data" folder.

This has been done to minimize clutter.

## COMPILATION

Enter the following command into the terminal to compile the program along with all dependencies:

**make**

## EXECUTION

The Program must be run with parameters in the following format: 

**./Task3.out -key a b -encrypt/-decrypt -in inputFile -out outputFile**
	
Eg: 
**./affineCiph.out -key 3 8 -encrypt -in file1.txt -out file2.txt** 
Or  
**./affineCiph.out -key 3 8 -decrypt -in file1.txt -out file2.txt** 

The order of the parameters (grouped) is variable	

## CLEAN

Enter the following command into the terminal to remove all objects and .out files associated with the program:

**make clean**

Contact me at mauricerizat@gmail.com to report bugs
