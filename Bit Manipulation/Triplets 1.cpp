#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    int c = 0;
    for(int i = 0;i < n;i++){
        int val = arr[i];
        for(int k = i+1;k < n;k++){
            val ^= arr[k];
            if(val == 0)
                c += k-i;
        }
    }
    cout << c;
}