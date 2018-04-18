// half_of_a_5x5_square.java

public class half_of_a_5x5_square {

	public static void main( String args[]) {

		for ( int n = 5; n > 0; n--) {

			for ( int c = 0; c < n; c++ ) {

				System.out.printf("%c", '#');

			}
			
			System.out.printf("%c", '\n');

		}	

	}

}
