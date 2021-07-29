#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans = 0;
    int x;
    for(int i = 0;i < N;i++){
        cin >> x;
        ans ^= (x+x);
    }
    cout << ans;
}