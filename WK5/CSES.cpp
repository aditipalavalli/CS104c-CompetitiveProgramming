/** solution to: https://www.cses.fi/problemset/task/1074/
 * Stick Lengths
*/

#include <iostream>
#include <vector>
using namespace std;

long calcCost (vector<int> array, int length){
    sort(array.begin(), array.end());
    int med = array[length/2];
    long answer = 0;
    for (int i = 0;i  < length; i++){
        answer += abs(med - array[i]);
    }
    return answer;
}

int main(){
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << calcCost(array, n);
}