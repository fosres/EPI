// fibonacci.cpp

/* Find the nth

   fibonacci number.
   
   

For reference, see https://math.stackexchange.com/questions/1145342/find-a-formula-for-the-nth-fibonacci-number
   
   

Simple formula to solve this:
   
   

F_(n+1) =F_n+F_(n-1)     ( F_0=0, F_1=1 )      



*/




#include <iostream>

using namespace std;



long long int F(long long int n) {
    
    

if ( n == 0 || n == 1)
        

	return n;
    
    

return F(n-1) + F(n-2);


}



int main() {
    
    

	long long int n;
    
    

	cout << "Enter the number n: " << endl;
    
    

	cin >> n;
    
    

	cout << "The nth number is: " << F(n) << endl;


}
