// remove_all_capital_letters.cpp

/*

Write a void function all_lower

that removes

all capital letters from a string

and returns the string in ALL

LOWERCASE LETTERS

*/

#include <iostream>
#include <string>
using namespace std;

void all_lower(char* input) {

    if ( *input == '\0' ) {
        return;
    }

    if ( *input >= 'A' && *input <= 'Z') {    
       *input += 32; // convert capital letter to lowercase
    }
    
    all_lower(++input); // simply move to next char in array
}

int main() {
   char test[] = "BrainS ARE tasty";
   all_lower(test);
   
   cout << test << endl;
   return 0;
}