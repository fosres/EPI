//decode_a_message.cpp

/* Convert a string stream
 *
 * containing a bunch of 
 *
 * strings representing
 *
 * integers into a 
 *
 * coherent English
 *
 * message.
 *
 * Terms:
 *
 * char input;
 *
 * int number = 0; -> holds int currently being appended
 *
 * bool IN_UPPERCASE_MODE = 1; -> indicates if program is interpreting
 *
 * uppercase letters
 *
 * bool in_lowercase_mode = 0; -> indicates if program is interpreting
 *
 * lowercase letters
 *
 * bool IN_PUNCTUATION_MODE = 0; -> indicates if program is interpreting
 *
 * punctuation marks
 *
 * const char UPPERCASE_LETTERS[] = " ABC...Z"; holds array of 
 *
 * UPPERCASE LETTERS
 *
 * for converting integer code into an English UPPERCASE LETTER
 *
 * const char lowercase_letters[] -> same idea as above
 *
 * const char PUNCTUATION_LETTERS[] -> same idea as above
 *
 *
 *
 * string decrypted_message[] = "";
 *
 * Conditions: 
 *
 * Input Range: [48, 57]
 *
 * And if the ASCII code of the char is not
 *
 * within this range the computer will 
 *
 * simply ignore that character.
 *
 * SEPARATE INTEGERS BY COMMAS
 *
 * How It Works:
 *
 * while (input != '\n')
 *
 * 1. Computer first checks if char is within Input Range, and if
 *
 * not, the computer will simply skip the char
 *
 * 2. Then the computer checks if the input == ','
 *
 *  If this is the case, then the computer will check 
 *
 *  which mode the program is and whether the currentmost
 *
 *  integer code, now fully stored in number, is divisble
 *
 *  by zero. If that is the case, the program changes
*
*  case mode. The hierarchy of case mode works like this:
*
*  if (IN_UPPERCASE_MODE)
	*
	*  change to in_lowercase_mode
	*
	*  number = 0; //must reset number for new integer code
	*
	*  continue;
*  else if (in_lowercase_mode)
	*  
	*  change to IN_PUNCTUATION_MODE
	*
	*  number = 0;
	*
	*  continue;
	*
*  else if (IN_PUNCTUATION_MODE)
	*
	*  change to IN_UPPERCASE_MODE
	*
	*  number = 0;
	*
	*  continue;
	*
*  And basically at this point the program will
*
*  now check what case mode the program is in, whether
*
*  the number is divisible by 27 if 
*
*  IN_UPPERCASE_MODE or IN_LOWERCASE_MODE or
*
*  divisible by 9 if IN_PUNCTUATION_MODE since
*
*  there are only 8 punctuation marks in the
*
*  English Language, and then concatenate
*
*  the English character to decrypted_message.
*
*  Finally, if the none of the above is true,
   
*  the program assumes the number is still 
*
*  being appended, and appends using the 
*
*  formula:
*
*  number = number * 10 + (int)(input) - CHAR_CODE_OF_ZERO;
*
*  Once number <= 0, the while loop exits and
*
*  the program prints whatever is in decrypted_message.
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {

	const int CHAR_CODE_OF_ZERO = 48;

	char input;

	int number = 0;

	bool IN_UPPERCASE_MODE = 1;
	
	bool in_lowercase_mode = 0;

	bool IN_PUNCTUATION_MODE = 0;

	const char UPPERCASE_LETTERS[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char lowercase_letters[] = " abcdefghijklmnopqrstuvwxyz";

	const char PUNCTUATION_LETTERS[] = " !?,. ;\"'";

	string decrypted_message = "";

		

	while ( (input = getchar() ) != '\n') {

		if ( input == ' ' || input == '\t')
			continue;


		if ( input == ',') {


			
			if ( IN_UPPERCASE_MODE && ( number % 27 == 0 ) ) {

				IN_UPPERCASE_MODE = 0;

				in_lowercase_mode = 1;

				IN_PUNCTUATION_MODE = 0;

				number = 0;

				continue;

			}

			else if ( in_lowercase_mode && (number % 27 == 0) ) {

				IN_UPPERCASE_MODE = 0;

                                in_lowercase_mode = 0;

                                IN_PUNCTUATION_MODE = 1;

                                number = 0;

                                continue;

			}

			else if ( IN_PUNCTUATION_MODE && (number % 9 == 0) ) {

				IN_UPPERCASE_MODE = 1;

                                in_lowercase_mode = 0;

                                IN_PUNCTUATION_MODE = 0;
				

                                number = 0;

                                continue;


			}

			else if ( IN_UPPERCASE_MODE && (number % 27 != 0) ) {

			decrypted_message += UPPERCASE_LETTERS[number%27];

			number = 0;
				continue;

			}


			else if ( in_lowercase_mode && (number % 27 != 0) ) {

			decrypted_message += lowercase_letters[number%27];

			number = 0;

                                continue;

			}





			else { // ( IN_PUNCTUATION_MODE && (number % 9 != 0) ) {

			decrypted_message += PUNCTUATION_LETTERS[number%9];

			number = 0;

			continue;

			}
		}

		else { // still reading integer code and appending digits to another

		number = number * 10 + ((int)(input) - CHAR_CODE_OF_ZERO);

		continue;

		}

	}

			
			if ( IN_UPPERCASE_MODE && ( number % 27 == 0 ) ) {

				IN_UPPERCASE_MODE = 0;

				in_lowercase_mode = 1;

				IN_PUNCTUATION_MODE = 0;

				number = 0;

				

			}

			else if ( in_lowercase_mode && (number % 27 == 0) ) {

				IN_UPPERCASE_MODE = 0;

                                in_lowercase_mode = 0;

                                IN_PUNCTUATION_MODE = 1;

                                number = 0;

                                

			}

			else if ( IN_PUNCTUATION_MODE && (number % 9 == 0) ) {

				IN_UPPERCASE_MODE = 1;

                                in_lowercase_mode = 0;

                                IN_PUNCTUATION_MODE = 0;
				

                                number = 0;

                                


			}

			else if ( IN_UPPERCASE_MODE && (number % 27 != 0) ) {

			decrypted_message += UPPERCASE_LETTERS[number%27];

			number = 0;
				

			}


			else if ( in_lowercase_mode && (number % 27 != 0) ) {

			decrypted_message += lowercase_letters[number%27];

			number = 0;

                                

			}





			else { // ( IN_PUNCTUATION_MODE && (number % 9 != 0) ) {

			decrypted_message += PUNCTUATION_LETTERS[number%9];

			number = 0;

			

			}

	cout << decrypted_message << endl;

	return 0;

	}








