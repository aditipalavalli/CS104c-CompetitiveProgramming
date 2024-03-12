#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, q, m;
    
    cin >> n;

    int nArr[n];

    for (int i = 0; i < n; i++){
        cin >> nArr[i];
    }

    sort(nArr, nArr+n);
    cin >> q;

    int answer = 0;
    for (int i = 0; i < q; i++){
        int x;
        cin >> x;
        answer = upper_bound(nArr, nArr+n, x) - nArr;
        cout << answer << endl;
        
    }


    

}