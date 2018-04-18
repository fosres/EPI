// half_of_a_5x5_square.cpp

/* Prints out a triangle that
 *
 * looks exactly like this:
 *
 * #####
 * ####
 * ###
 * ##
 * #
 *
 * Conditions:
 *
 * Only allowed to use two
 * output statements:
 *
 * cout << "#";
 *
 * AND
 *
 * cout << "\n";
 *
 */

#include <iostream>
using namespace std;

int main() {

	for ( int n = 5; n > 0; n--) {

		for ( int c = 0; c < n; c++ ) {

			cout << "#";

		}
			
		cout << "\n";
	}

}
