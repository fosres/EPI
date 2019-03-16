public class swap_bits{

     public static long swap_bits (long i, long j, long input) {
         
         long c = 0;
         
         String swapped_number = "";
         
         if ( input == 1 || input == 0)
                return input;
                
         while (input > 0) {
            
            if ( c == i || c == j) {
                swapped_number = Long.toString(~(input&1)) + swapped_number;
            }
            else { //just append bit
            
                swapped_number = Long.toString((input&1)) + swapped_number;
            }
            
            input >>= 1;
            c++;
         
         }
         
         return Long.parseLong(swapped_number, 2);
         
     }
     
     public static void main(String []args){
        long ans = (swap_bits(0, 2, 6) );
	System.out.println(ans);
     }
}
