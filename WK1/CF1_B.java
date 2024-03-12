/** solution to  https://codeforces.com/contest/1354/problem/B/ 
 * Ternary Strings
*/

import java.util.*;
import java.io.*;

public class CF1_B {
    public static void main (String[] args){
        Scanner in = new Scanner(System.in);
        int len = in.nextInt();

        String[] arr = new String[len];
        
        for (int i = 0; i < len; i++){
            arr[i] = in.next();
        }

        for (int i = 0; i < len; i++){
            String s = arr[i];
            int min = Integer.MAX_VALUE;
            int[] ar = new int[3];
            ar[0] = -1;
            ar[1] = -1;
            ar[2] = -1;

            for (int j = 0; j < s.length(); j++){
                int curr = Integer.parseInt(s.substring(j, j+1));
                
                ar[curr -1] = j;

                // calculate min and max
                if (ar[0] != -1 && ar[1] != -1 && ar[2] != -1){
                    int highest = Math.max(ar[0], Math.max(ar[1], ar[2]));
                    int lowest = Math.min(ar[0], Math.min(ar[1], ar[2]));

                    if (highest-lowest + 1 < min ) min = highest-lowest + 1;
                }

            }



            if (ar[0] == -1 || ar[1] == -1 || ar[2] == -1){
                System.out.println(0);
            } else {
                System.out.println(min);
            }
        }
        
    }
}
