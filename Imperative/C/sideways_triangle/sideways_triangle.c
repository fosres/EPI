// sideways_triangle.c

/* Write a program that uses 
    only two output statements,
    
    cout << "#" and cout << "\n",
    
    to produce a pattern of hash
    
    symbols shaped like a sideways
    
    triangle.
    
    #
    ##
    ###
    ####
    ###
    ##
    #

*/

#include <stdio.h>


int main() {
    
    for ( int n = 1; n <= 4; n++) {
        
        for ( int c= 0; c < n; c++ ) {
           
           printf("%c", '#'); 
            
        }
        
            printf("%c", '\n');
        
        }  
        
    
    
    
    for ( int n = 3; n > 0; n--) {
        
        for ( int c= 0; c < n; c++ ) {
           
           printf("%c", '#'); 
            
        }
        
            printf("%c", '\n');
        
        }  
        
    }