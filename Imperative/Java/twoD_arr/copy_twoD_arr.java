public class copy_twoD_arr {
    
    
    public static int[][] copy_array(int input[][]) {
        
        int copycat[][] = new int[input.length][];
        
        for ( int i = 0; i < copycat.length; i++)                   {
            copycat[i] = new int[input[i].length];
        }
     
        for ( int i = 0; i < copycat.length; i++)               {
            
            for ( int j = 0; j < copycat[i].length; j++)    {
                copycat[i][j] = input[i][j];
            }  
        }
        
        return copycat;
        
    }

     public static void main(String []args){
        
        int input[][] = new int[50][48];
        
        int c = 0;
        
        for ( int i = 0; i < input.length; i++)             {
            for (int j = 0; j < input[i].length; j++)               {
                input[i][j] = 1;
               
            }
        }
        
        copy_array(input);
         
         
     }
}
