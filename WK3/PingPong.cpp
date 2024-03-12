/** solution to: https://codeforces.com/contest/320/problem/B/
 * Ping-Pong (Easy Version)
*/

#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <set>


void possible (int intervals[111][2], int start, int end, bool visited[111], int count){
    int a = intervals[start][0];
    int b = intervals[start][1];
    
    //printf("checking for %d to %d\n", start, end);

    for (int i = 0; i < count; i++){
        
        if (visited[i]) {
            //printf("pass %d\n",i);
            continue;
        }
        

        int c = intervals[i][0];
        int d = intervals[i][1];
        //printf("checking interval %d %d\n", c, d);
        if (((c < a) && (a < d)) || ((c < b) && (b < d))){
            //printf("INNNNNN\n");
            visited[i] = true;
                //printf("FOUND THE END\n");
                //printf("i've visited so far\n");
            possible (intervals, i, end, visited, count);
        }
    }

}

int main(){
    int numQueries;
    cin >> numQueries;
    
    int count = 0;

    int intervals[111][2];

    for (int i = 0; i < numQueries; i++){
        int typeQuery;
        cin >> typeQuery;
        int x, y;
        cin >> x >> y;

        if (typeQuery == 1){
            intervals[count][0] = x;
            intervals[count][1] = y;
            count++;
        } else {
            bool visited[111];
            memset (visited, false, sizeof visited);
            x--;
            y--;
            visited[x] = true;
            possible(intervals, x, y, visited, count);
            if (visited[y]){
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }


    return 0;
}