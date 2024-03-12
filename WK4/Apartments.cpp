#include <stdio.h>
#include <iostream>
#include <array>
#include <functional>
#include <algorithm>

using namespace std;

int main(){


    int n, m, k;
     
    cin >> n >> m >>k;

    int apps[n];
    int aprs[m];

    for (int i = 0; i < n; i++){
        cin >> apps[i];
    }

    for (int i = 0; i < m; i++){
        cin >> aprs[i];
    }

    sort(apps, apps + n);
    sort(aprs, aprs + m);

    int res = 0;
    
    int a = 0, b = 0;

    while (b < m && a < n){
        if (abs(apps[a]- aprs[b]) <= k){
            a++;
            b++;
            res++;
        } else if (apps[a] > aprs[b]){
            b++;
        } else {
            a++;
        }
    }

    cout << res;


};