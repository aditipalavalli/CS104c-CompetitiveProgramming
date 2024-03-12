/** solution to: https://codeforces.com/contest/405/problem/A/ 
 * Gravity Flip
*/

package WK0;
import java.util.Scanner;
import java.util.Arrays;

public class CF0 {
    public static void main(String[] args){

        Scanner in = new Scanner (System.in);
        int numCol = in.nextInt();
        int[] colStacks = new int[numCol];
        for (int i =0; i < numCol; i++){
            colStacks[i] = in.nextInt();
        }

        // sort them in ascending order
        Arrays.sort(colStacks);

        for (int e : colStacks){
            System.out.print(e + " ");
        }
    }
}
