#include <iostream>
#include <stdexcept>
#include "mat.hpp"
#include <string>
#include <algorithm>

using namespace std;
/**
* This function gets number of columns, number of rows, and two chars.
* The function returns a string that will represent the mattress producted using the inputs.
*/
string ariel::mat(int columns, int rows, char ch1, char ch2) {
	// mat size need to be odd
	if (rows % 2 == 0 || columns % 2 == 0) {
		throw invalid_argument("Mat size is always odd");
	}
	// mat size need to be positive
	if (rows < 0 || columns < 0) {
		throw invalid_argument("Mat size is always positive");
	}
	// character need to be legal
	if (ch1 < '!' || ch2 < '!' || ch1 > '~' || ch2 > '~') {
		throw invalid_argument("Invalid charcters");
	}
	string mattress; // the string we will return
	for (int i = 0; i < rows; i++) {
		int orig_index = i; // saving the original index
		// the mattress need to be symetric
		if (i > rows / 2)
		{
			i = rows - i - 1;
		}
		for (int j = 0; j < columns; j++) {
			// if we are on the 'edges' of the row (note that the 'edges' are changing from row to row)
			if (j <= i || columns -1 - j <= i) {
				if (j % 2 == 0) { // if the column is even
					mattress += ch1;
				}
				else { // if the column is odd
					mattress += ch2;
				}
			}
			else { // if we are on the 'middle' of the row
				if (i % 2 == 0) { // if the row is even
					mattress += ch1;
				}
				else { // if the row is odd
					mattress += ch2;
				}
			}
		}
		i = orig_index; // return to the original index
		if (i != rows - 1) { // going down only if we are not in last row
			mattress += "\n";
		}
	}
	return mattress;
}
