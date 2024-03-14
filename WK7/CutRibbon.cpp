/** solution to: https://codeforces.com/contest/189/problem/A/
 * Cut Ribbon
*/

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

int main (){
    int n; 
    int arr[3];
    cin >> n >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr + 3);

    int dp [n + 1];
    
    memset(dp, 0, sizeof(dp));

    dp[arr[0]] = 1;

    // for (int i = 0; i <= n; i++){
    //     cout << dp[i] << " ";
    // }

    for (int i = arr[0] + 1; i <= n; i++){
        int temp [3];
        memset(temp, 0, sizeof(temp));

        for (int j = 0; j < 3; j++){
            if ((i - arr[j] > 0 && dp[i-arr[j]] > 0) || i - arr[j] == 0){
                temp[j] = dp[i-arr[j]] + 1;
            }
        }

        dp[i] = *std::max_element(temp, temp+3);
    }

    cout << dp[n];

}