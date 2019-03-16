import java.lang.*;
public class count_bits {
	
	/*
	int i = 0;

	if ( input == 0 || input == 1) {
		
		return 	1;

	}

	while ( input ) {

		i++;

		input>>= 1;

	}

	retuern i;
	*/
	public int count_bits(long input) {
	
		return bitCount(input);

	}

	public static void main(String args[] ) {

		System.out.println(count_bits(32));


	}






}
