public class reverse_bits {

	public static unsigned long reverse_bits (unsigned long input) {

		StringBuffer number = new StringBuffer(input);

		reverse(number);

		return Long.parseLong(number,2);

	}

	public static void main(String args[] ) {

		System.out.println(reverse_bits(100));	




	}






}
