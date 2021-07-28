#include<bits/stdc++.h>
using namespace std;
int B2D(string str){
    int ans = 0;
    int n = str.length()-1;
    for(int i = 0;i < str.length();i++){
        if(str[i] == '1')
            ans += pow(2, n);
        n--;
    }
    return ans;
}

void GC(vector<int> &ans, vector<string> &v, int n){
    if(ans.size() >= n)
        return ;
    int limit = v.size()-1;
    for(int i = limit; i >= 0;i--){
        ans.push_back(B2D('1' + v[i]));
        v.push_back('1' + v[i]);
    }
    for(int i = 0; i <= limit;i++)
        v[i] = '0' + v[i];
    GC(ans, v, n);
}
vector<int> grayCode(int n) {
    vector<int> ans;
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    ans.push_back(0);
    ans.push_back(1);
    int N = pow(2, n);
    GC(ans, v, N);
    return ans;
}
int main(){
    int N;
    cin >> N;
    vector<int> v = grayCode(N);
    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";
}