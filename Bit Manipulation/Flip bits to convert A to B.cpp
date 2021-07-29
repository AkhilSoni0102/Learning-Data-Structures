#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    int ans = A ^ B;
    int c = 0;
    while(ans != 0){
        ans = ans - (ans & (-ans));
        c++;
    }
    cout << c;
}