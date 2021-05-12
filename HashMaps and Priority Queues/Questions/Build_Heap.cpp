#include<bits/stdc++.h>
using namespace std;
void insert(int value, vector<int> &pq){
        pq.push_back(value);
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex - 1) / 2;
        while(childIndex > 0){
            if(pq[childIndex] > pq[parentIndex])
                swap(pq[childIndex], pq[parentIndex]);
            else 
                break;
           	childIndex = parentIndex;
			parentIndex = (childIndex - 1) / 2;
        }
    }

vector<int> buildHeap(vector<int> arr, int n){
	vector<int> pq;
    for(int i = 0; i < arr.size();i++)
        insert(arr[i], pq);
   	return pq;
}
