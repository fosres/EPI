//char_digit_to_int

/* Taken from "Think Like A Programmer" by V. Anton Spraul, p. 35
 *
 * Specs: Program converts a character 
 *
 * representing a single base-10 digit
 *
 * that is from '0' to '9'. The program
 *
 * converts this char(acter) digit to
 *
 * an int and outputs the int.
 *
 * The following table shows the
 *
 * ASCII codes for the single base-10
 *
 * char digits.
 *
 * ASCII Character Code for Digit
 * Character	Character Code	Desired Integer	Difference
 * '0'		48		0		48
 * '1'		49		1		48
 * '2'		50		2		48
 * '3'		51		3		48
 * '4'		52		4		48
 * '5'		53		5		48
 * '6'		54		6		48
 * '7'		55		7		48
 * '8'		56		8		48
 * '9'		57		9		48
 *
 * Terms:
 *
 * char input
 *
 * const int CHAR_CODE_OF_ZERO = 48;
 *
 * int desired_int;
 *
 * Conditions:
 *
 * Input char range: ['0','9']
 *
 * Output must be the corresponding int form
 *
 * of the value of the char.
 *
 * For example: '0' -> 0 or '9' -> 9
 *
 * How It Works:
 *
 * It just does this:
 *
 * int desired_int = (int)(input) - CHAR_CODE_OF_ZERO;
 *
 * cout << desired_int << endl;
 */

#include <iostream>
using namespace std;

int main() {

	char input;

	cout << "Enter character digit below:" << endl;

	cin >> input;

	const int CHAR_CODE_OF_ZERO = 48;

	int desired_int = (int)(input) - CHAR_CODE_OF_ZERO;

	cout << desired_int << endl;


}
