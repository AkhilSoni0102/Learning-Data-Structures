#include<bits/stdc++.h>
using namespace std;
int minSwaps(vector<int> &arr)
{
    map<int, int> h;
    int c = 0;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    for(int i = 0;i < arr.size();i++)
        h[arr[i]] = i;
   	for(int i = 0;i < arr.size();i++){
        if(arr[i] != temp[i]){
            c++;
            int k = arr[i];
            swap(arr[i], arr[h[temp[i]]]);
			h[k] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
	return c;
}