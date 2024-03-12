/** solution to: https://www.cses.fi/problemset/task/1623/
 * Apple Division
*/

#include <iostream>
#include <climits>
using namespace std;


int main(){
    int n;
    cin >> n;
    long arr[n];
    long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    long answer = LONG_MAX;
    int i = 0;
    while (i < 1<<n){
        long curr = 0;
        int j = 0;
        while(j < n){
            if (i & 1<<j && true) {
                curr += arr[j];
            }
            j++;
        }
        long currJ = abs(sum-(2 * curr));
        answer = min(answer, currJ);
        i++;
    }
    cout << answer;




    return 0;
}