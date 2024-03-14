/** solution to: https://www.cses.fi/problemset/task/1633/
 * Dice Combinations
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){

    int n;
    cin >> n;

    long arr[n+1];
    memset(arr, 0, (n+1) * sizeof(long));

    arr[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int dice = 1; dice <= 6 && (i-dice >= 0); dice++){
            arr[i] += (arr[i - dice]) % (1000000000+7);
        }
    }
    
    cout << arr[n] % (1000000000+7);
    
}