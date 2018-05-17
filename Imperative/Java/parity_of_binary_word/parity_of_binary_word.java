//parity_of_binary_word.java

public static boolean parity(long input) {

	int c;

	while (input > c ) {
		
		c = c + (input & 1);

		input >>= 1;

	}

	return !(c % 2 == 0);

}

public static void main(String args[] ) {

	System.out.println(parity(43));

}
