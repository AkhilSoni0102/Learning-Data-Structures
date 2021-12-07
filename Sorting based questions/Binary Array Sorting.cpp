#include<bits/stdc++.h>
using namespace std;
vector<int> sortBinaryArray(vector<int> arr, int n)  {
 	int m = 0;
    for(int i = 0;i < n;i++)
        if(arr[i] == 0){
            swap(arr[i], arr[m]);
            m++;
        }
   	return arr;
}