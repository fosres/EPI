//luhn_checksum_validation.cpp

// Taken from "Think Like a Programmer", V. Anton Spraul, p.31

/* Terms:
 *
 * long long int number = input number

 * long long int last_digit = stores last digit of 

 * remaining digits in number

 * long long int reverse = stores reversed number

 * as it is appended into this variable
 *
 * How It Works:
 *
 * Take a registered ID number and starting 
 *
 * from the RIGHMOST digit add digits. Double
 *
 * every other digit DIRECTLY and to the others
 *
 * IFF doubled digit < 10. IFF doubled digit > 10.
 *
 * IFF doubled digit > 10, each of those digits
 *
 * are added separately with the rest of the
 *
 * numbers. If the sum % 10 != 0, add a check
 * 
 * digit to render the new net sum divisible
 *
 * by 10. 
 *
 * Here is an example: 176248 is a registered
 *
 * identification number 
 *
 * <----	<----		<----
 * 1	7	6	2	4	8
 *
 * 1	14	6	4	4	16
 *
 * 1	1+4  + 	6   +	4   + 	4   +  1+6 = 27 + 3* = 30
 *
 * *Check digit to render sum divisible by 10
 *
 * -----------------------------------------------------
 *
 *  NOTE: WHAT IS PROGRAMMED IS DESCRIBED BELOW:
 *  
 *  Now lets say the rendered checksum is inputted
 *
 *  into the computer, and the computer will check if
 *
 *  rendered checksum is compliant wit the Luhn_checksum.
 *
 *  This is programmed below, NOT what is above the dotted
 *
 *  line. 
 *
 *  Starting from the LEFTMOST digit, add digits. add digits
 *
 *  and double every other digit DIRECTLY and add to the 
 *
 *  others IFF doubled digit < 10. IFF double digit makes
 *
 *  a two digit number, each of the these digits are added
 *
 *  separately. If sum is divisible by 10, the number is
 *
 *  valid. 
 *
 *  1	7	6	2	4	8 | 3
*   1 	14	6	4	4	16 | 3
*   1 + 1+4	6   +  	4   +	4   +	1+6 | 3 
*   ----->	----->		---->		
*   
*   For directions on how to reverse a number, see 
*
*   palindrome.cpp
*/

#include <iostream>
using namespace std;
#include <stdbool.h>

int main() {

	// Copy lines [101,122] from palindrome.cpp
	// and paste here!
	
	long long int number; // == input number

	cout << "Input a nonnegative ID:" << endl;

	cin >> number;

	// Stores number so value can be printed in cout below

	long long int last_digit;

	

/* An input of say, 176248 | 3 now reversed to be 3 | 842671 */

	int validate_checksum = 0;

	int c = 1;

	while (number > 0) {

		last_digit = number % 10;

		if ( c % 2 == 0 ) { // if digit is one of the "every other digit"

			last_digit *= 2;

			if ( last_digit >= 10) {

				validate_checksum += (last_digit/10) + (last_digit % 10);

			}
			else // last_digit < 10
				validate_checksum += last_digit;



		}
		else { // digit is NOT one of "every other digit"

			validate_checksum += last_digit;

		}

			number /= 10;

			c++;


	}

	cout << "is Luhn checksum valid?: ";

	cout << (validate_checksum % 10 == 0) << endl;

}

