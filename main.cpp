/*
AFFINE CIPHER
*/

#include "header.h"

int main(int argc, char** argv)
{
	//Welcome Message
	cout << "\nWelcome to Affine Cipher Program " << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "\nProcessing Terminal Input:\n" << endl;
	
	int a = -1;	//Stores a component of key
	int b = -1; //Stores b component of key
	string inFile = ""; //Store name of Input file
	string outFile = ""; //Stores name of Output file
	string type = ""; //Stores type of operation to be done - encryption or decryption
	string input = ""; //Stores read input data - text 
	string output = ""; //Stores recieved output data - to be writtten
	
	//Actual processing of Terminal Input
	try
	{
		for (int i = 1; i < argc; ++i)
		{
			string curr = argv[i];
			
			if (curr == "-key") //Identifying key marker
			{
				a = stoi(argv[i+1]);
				b = stoi(argv[i+2]);
			}
			else if (curr == "-in") //Identifying input file name marker
				inFile = argv[i+1];
			else if (curr == "-out") //Identifying output file name marker
				outFile = argv[i+1];
			else if (curr == "-encrypt" || curr == "-decrypt") //Identifying operation type marker
				type = curr;
		}	
	} 
	catch (const exception& e) //Errors in processing input data (e.g. Wrong data type) will be processed here
	{
		cout << "Error in processing input data. Please fix input data and try again\n" << endl;
	}
	
	if (a == -1 || b == -1 || inFile == "" || outFile == "" || type == "") //In case of missing data
	{
		cout << "Parameters are either wrongly typed or incomplete.";
		cout << "\nProgram must be run with parameters in the following format: ";
		cout << "\n\n\t./Task3.out -key a b -encrypt/-decrypt -in inputFile -out outputFile";
		cout << "\n\n\tEg: ./Task3.out -key 3 8 -encrypt -in file1.txt -out file2.txt";
		cout << "\n\tOr  ./Task3.out -key 3 8 -decrypt -in file1.txt -out file2.txt";
		cout << "\n\nThe order of the parameters (grouped) is variable";	
		cout << "\n\nPlease make sure all requirements are met and run the program again ";
		cout << "\nwith the correct format.\n" << endl;	
		return 0;
	}
	
	bool validKey = checkKey (a, b); //Check validity of key
	
	if (validKey)
		cout << "\n\tThe key is valid" << endl;
	else
		cout << "\n\tThe key is invalid" << endl;
	
	cout << "\n\nChecking Input, Output files:" << endl; //Check validity of Input file. If valid, read Input file
	
	//Checking for and reading Input file
	ifstream readFile("data/" + inFile); //File to be located in "data" sub-folder
	if (!(readFile.is_open())) //Input file cannot be opened or does not exist
	{
		cout << "\n\tFile named \"" << inFile;
		cout << "\" cannot be opened or does not exist.";
		cout << "\n\tPlease try again with a valid file name.\n" << endl;
		return 0;
	}	
	else //Input file exists
	{	
		cout << "\n\tInput, Output files are valid\n" << endl;
		
		if (!validKey) //Check is done here so that in case of errors (key and input file) both will be shown
			return 0;
	
		cout << "\nReading from Input file..." << endl;
		
		//Reading Input file
		try 
		{
			string line;
			while (getline(readFile, line))
				input += (line + "\n");
			
			input = input.substr(0, input.size()-1);
			
		readFile.close();
		} 
		catch (exception& e) //Handles errors that occurs during file reading
		{
			cout << "An error occured while reading file. Please try again.\n" << endl;
			return 0;
		}
	}
	
	cout << "\nFile Read!\n" << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	//Affine Cipher operation	
	if (type == "-encrypt") 	
		output = encrypt (a, b, input);
	else if (type == "-decrypt")
		output = decrypt (a, b, input);
	else
		cout << "Somehow, the impossible has happened" << endl; //Can't happen. For testing purposes.
	
	//Writing to file
	ofstream writeFile;
	writeFile.open ("data/" + outFile);
	writeFile << output << endl;
	writeFile.close();
	
	cout << "\n--------------------------------------------------------------" << endl;
	cout << "Thank you for using the program" << endl;
	
	return 0;
}
