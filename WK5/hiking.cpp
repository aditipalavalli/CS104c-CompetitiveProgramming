#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;


bool largerValue (vector<int>& arr, int x, int y){
    x--;
    y--;
    int start = min(x, y);
    int end = max(x, y);
    // int max = 0;
    // if (arr[start] > arr[end]){
    //     max = arr[start];
    // } else {
    //     max = arr[end];
    // }
    // printf("max: %d\n", max);
    // printf("start: %d, end: %d\n", arr[start], arr[end]);
    // for (int i = start+1; i < end; i++){
    //     // printf("in loop: %d curr value: %d\n", i, arr[i]);
    //     if (arr[i] >= max){
    //         return true;
    //     }
    // }
    // return false;
    // for (int i = start + 1; i < end; i++) {
    //     if (arr[i] > max) {
    //         max = arr[i];
    //     }
    // }
    // // printf("max found: %d\n", max );
    // return max >= arr[start] && max >= arr[end];
    int maxElevation = max(arr[start], arr[end]);
    for (int i = start + 1; i < end; i++) {
        if (arr[i] >= maxElevation) {
            return true; // There is a point blocking the view

        }
    }
    return false; // No point blocking the view
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if (x == y || y-x == 1){
            printf("yes\n");
        } else if(largerValue(arr, x, y)){
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }

}
