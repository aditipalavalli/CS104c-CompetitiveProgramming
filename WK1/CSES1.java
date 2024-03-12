/** solution to: https://www.cses.fi/problemset/task/1661/
 * Subarray Sums II*/ 

import java.util.*;
import java.util.Arrays;
import java.io.*;

public class CSES1 {

    public static void main (String[] args){
        Scanner in = new Scanner (System.in);
        int len = in.nextInt();
        long target = in.nextLong();
        long curr = 0;
        long counter = 0;

        HashMap<Long, Long> prefixSum = new HashMap<Long, Long>();
        long zero = 0;
        long one = 1;
        prefixSum.put(zero, one);

        for (int i = 0; i < len; i++){
            curr += in.nextInt();
            if (prefixSum.containsKey(curr - target)){
                counter += prefixSum.get(curr-target);
            }

            if (prefixSum.containsKey(curr)){
                long oldValue = prefixSum.get(curr);
                prefixSum.put(curr, oldValue+ 1);
            } else {
                prefixSum.put(curr, one);
            }
        }

        in.close();
        System.out.print(counter);

    }


}
