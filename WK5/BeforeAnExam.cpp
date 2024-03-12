/** solution to: https://codeforces.com/contest/4/problem/B/
 * Before An Exam
*/

#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int d, sumTime;
    cin >> d >> sumTime;
    int mins[d];
    int maxs[d];
    for (int i = 0; i < d; i++){
        cin >> mins[i] >> maxs[i];
    }

    int min = accumulate(mins, mins+d, 0);
    int max = accumulate(maxs, maxs+ d, 0);


    if (min <= sumTime && sumTime <=max){
        printf("YES\n");
        for (int j = 0; j < d; j++){
            int spendToday;
            if (mins[j]+sumTime - min < maxs[j]){
                spendToday = mins[j]+sumTime - min;
            } else {
                spendToday = maxs[j];
            }
            sumTime -= (spendToday - mins[j]);
            printf("%d ", spendToday);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }


    return 0;
}