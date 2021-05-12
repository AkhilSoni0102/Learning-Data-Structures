#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    vector<int> pq;

    int Size(){
        return pq.size();
    }
    
    bool isEmpty(){
        return pq.size() == 0;
    }

    int getMin(){
        if(isEmpty())
            return 0;
        return pq[0];
    }

    void insert(int value){
        pq.push_back(value);
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex - 1) / 2;
        while(childIndex > 0){
            if(pq[childIndex] < pq[parentIndex])
                swap(pq[childIndex], pq[parentIndex]);
            else 
                break;
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    int removeMin(){
        int value = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int PI = 0;
        int LCI = 1;
        int RCI = 2;
        int MI = 0;
        while(LCI < pq.size()){
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
            MI = PI;
        }
        return value;
    }
};


int main(){
    MinHeap p;
    p.insert(100);
    p.insert(10);
    p.insert(23);
    p.insert(59);
    p.insert(20);
    p.insert(40);
    p.insert(19);

    cout<<p.Size()<<endl;
    while(!p.isEmpty())
        cout<<p.removeMin()<<endl;
    cout<<p.Size();
}