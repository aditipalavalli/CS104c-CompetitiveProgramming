/** solution to  https://codeforces.com/contest/295/problem/A/
 * Greg and Array
*/

import java.util.*;
import java.io.*;

public class CF1 {
    public static void main (String[] args){
        Scanner in = new Scanner (System.in);

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        int[][] operations = new int[m][3];

        long[] arr = new long[n];

        for (int i = 0; i < n; i++){
            arr[i] = in.nextLong();
        }

        for (int i = 0; i < m; i++){
            operations[i][0] = in.nextInt() - 1;
            operations[i][1] = in.nextInt() - 1;
            operations[i][2] = in.nextInt();
        }

        //System.out.println(operations[0][0] + " " + operations[0][1] + " " + operations[0][2]);

        int[] queries = new int[m];
        for (int i = 0; i < k; i++){
            int start = in.nextInt() - 1;
            int end = in.nextInt() - 1;
            while (start <= end){
                queries[start]++;
                start++;
            }
        }
        in.close();
        //System.out.println(queries[0] + " " + queries[1] + " " + queries[2]); 

        // apply operations
        for (int i = 0; i < m; i++){
            for (int j = operations[i][0]; j <= operations[i][1]; j++){
                arr[j] += queries[i] * operations[i][2];
            }
        }

        // for (int i = 0; i < k; i++){
        //     for (int x = operations[j][0]; x <= operations[j][1] && x < n; x++){
        //         arr[x] += operations[j][2];
        //     }
        // }

        //     for (int j = start; j <= end; j++){
        //         for (int x = operations[j][0]; x <= operations[j][1] && x < n; x++){
        //             arr[x] += operations[j][2];
        //         }
        //     }
        // }

        for (long i : arr){
            System.out.print(i + " ");
        }


    }

}
