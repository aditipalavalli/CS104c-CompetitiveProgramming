/** soluion to: https://codeforces.com/contest/520/problem/B/
 * Two Buttons
 */

package WK2;
import java.util.*;
import java.io.*;

public class CF2 {
    public static void main (String[] args){
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long m = in.nextLong();
        in.close();


        if (n == m) {
            System.out.print(0);
            return;
        }

        int count = 0;

        while (m > n){
            if (m%2 == 0){
                m /=2;
            } else {
                m +=1;
            }
            count++;
        }

        count += (n -m);
        System.out.print(count);

    }
}

