#include<bits/stdc++.h>
using namespace std;
void minHeapToMaxHeap(long *arr, int n)
{
    int m = 0;
    for(int i = 0;i < n; i++){
        arr[m] = arr[i];
        int childIndex = m;
        int parentIndex = (childIndex - 1) / 2;
        while(childIndex >=0 ){
            if(arr[childIndex] > arr[parentIndex])
                swap(arr[childIndex], arr[parentIndex]);
           	else 
                break;
           	childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        }
        m++;
    }
}