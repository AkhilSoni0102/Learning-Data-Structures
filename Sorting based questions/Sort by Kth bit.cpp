#include<bits/stdc++.h>
using namespace std;
vector < int > sortArrayByKBit(int n, int k, vector < int > & arr) {
    int j = 0;
    int p = 0;

    vector < int > temparr(n);
    for (int i = 0; i < n; i++) {
        if ((arr[i] >> (k - 1)) % 2 == 0) {
            arr[p++] = arr[i];
        }
        else {
            temparr[j++] = arr[i];
        }
    }

    j = 0;
    for (int i = p; i < n; i++) {
        arr[i] = temparr[j++];
    }
    return arr;
}