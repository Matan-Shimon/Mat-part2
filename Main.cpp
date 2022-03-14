#include <iostream>
#include <stdexcept>
#include "mat.hpp"
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
using namespace ariel;

/**
  To run the main program:
  1. Move to ubunto environment.
  2. Enter: make main
  3. Enter: ./main
  4. Follow the instrunctions.
*/

// func to check if the string can be casted to an int
bool isNumber(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0) { // the first char can be a negative sign
			if (str[i] != '-' && isdigit(str[i]) == 0) {
				return false;
			}
		}
		else {
			if (isdigit(str[i]) == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cout << "The numbers must be positive and odd\n";
	cout << "If you won't follow the instructions, an error will occur" << endl;
	bool done = false;
	while (!done) { // will happen until a mattress will be printed
		string sn1, sn2; // for the numbers input validation
		int n1, n2; // for the mattress size
		string sc1, sc2; // for the characters input validation
		char c1, c2; // for the mattress characters
		cout << "Enter a valid number: ";
		cin >> sn1; // getting the input from the user
		while (!(isNumber(sn1))) {
			cout << "The input was not valid, Enter a valid character: ";
			cin >> sn1; // getting the input from the user again
		}
		// if the code got here, it means that the string is actually a number,
		// means we can cast this string into an int using "istringstream".
		istringstream(sn1) >> n1;
		cout << "Enter another valid number: ";
		cin >> sn2; // getting the input from the user
		while (!(isNumber(sn2))) {
			cout << "The input was not valid, Enter a valid character: ";
			cin >> sn2;
		}
		// if the code got here, it means that the string is actually a number,
		// means we can cast this string into an int using "istringstream".
		istringstream(sn2) >> n2;

		cout << "Enter a valid char: ";
		cin >> sc1; // getting the input from the user
		while (sc1.length() != 1) {
			cout << "The input was not valid, Enter a valid character: ";
			cin >> sc1; // getting the input from the user again
		}
		// if the code got here, it means that the string the user provided has only on char
		// means we can cast this string into a character using "*sc1.c_str()"
		c1 = *sc1.c_str();
		cout << "Enter another valid char: ";
		cin >> sc2; // getting the input from the user
		while (sc2.length() != 1) {
			cout << "The input was not valid, Enter a valid character: ";
			cin >> sc2; // getting the input from the user again
		}
		// if the code got here, it means that the string the user provided has only on char
		// means we can cast this string into a character using "*sc1.c_str()"
		c2 = *sc2.c_str();
		try {
			cout << mat(n1, n2, c1, c2) << endl;
			done = true;
		}
		catch (invalid_argument err) {
			cout << "\n" << err.what();
			cout << "\nPlease follow the intructions!\n" << endl;
		}
	}
	cout << "\nEnjoy your new mattress!" << endl;
}