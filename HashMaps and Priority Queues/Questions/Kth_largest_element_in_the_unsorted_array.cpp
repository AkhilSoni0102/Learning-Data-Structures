#include<bits/stdc++.h>
using namespace std;
class PriorityQueue{
    public:
    vector<int> pq;
    int getMin(){
        if(isEmpty())
            return 0;
        return pq[0];
    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int Size(){
        return pq.size();
    }
    void insert(int value){
        pq.push_back(value);
        int childIndex = pq.size()-1;
        int parentIndex;
        while(childIndex > 0){
            parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex])
                swap(pq[childIndex], pq[parentIndex]);
            else 
                break;
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty())
            return 0;
        int value = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int PI = 0;
        int LCI = 1;
        int RCI = 2;
        int MI = 0;
        while(LCI < pq.size()){
            MI = PI;
            if(pq[LCI] < pq[MI])
                MI = LCI;
            if(pq[RCI] < pq[MI] && RCI < pq.size())
                MI = RCI;
            if(MI == PI)
                break;
            swap(pq[MI], pq[PI]);
            PI = MI;
            LCI = 2 * PI + 1;
            RCI = 2 * PI + 2;
        }
        return value;
    }
};

int kthLargest(vector<int>& arr, int size, int K)
{
	PriorityQueue p;
    for(int i = 0;i < size;i++){
        if(i < K)
            p.insert(arr[i]);
       	else 
        {
            int val = p.getMin();
            if(val < arr[i]){
                p.removeMin();
                p.insert(arr[i]);
            }
        }
    }
    int v = p.getMin();
    return v;
}