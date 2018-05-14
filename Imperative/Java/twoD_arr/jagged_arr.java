/* Initialize a jagged array whose first 
 * 
 * row has space to store one value, the
 *
 * second row can store 2 values, the 
 *
 * third row has space to store 3 values,
 *
 * and so on until the 50th row has space
 *
 * to store 50 values.
 */

public class jagged_arr{

     public static void main(String []args){
        
        int input[][] = new int[50][48];
        
        int c = 0;
        
        for ( int i = 0; i < input.length; i++)             {
            for (int j = 0; j < input[i].length; j++)   {
                input[i][j] = 1;
               
            }
        }
        
        int sum = 0;
        
        for ( int i = 0; i < input.length; i++)             {
            for (int j = 0; j < input[i].length; j++)   {
                System.out.print(input[i][j]+" ");
		sum += input[i][j];
            }
            System.out.println();
        }
        
        System.out.println(sum);
        
     }
}
