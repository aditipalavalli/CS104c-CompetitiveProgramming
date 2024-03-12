/** solution to: https://www.cses.fi/problemset/task/1068/ 
 * Weird Algorithm
 */

package WK0;
import java.util.Scanner;

public class CSES0 {
    public static void main (String[] args){
        Scanner in = new Scanner(System.in);
        long var = in.nextLong();
        System.out.print(var + " ");
        
        while (var != 1){
            if (var %2 == 0){
                var /= 2;
            } else {
                var = var * 3 + 1;
            }
            System.out.print(var + " ");
        }

    }
}