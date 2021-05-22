#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    vector<int> pq;

    bool isEmpty(){
        return pq.size() == 0;
    }

    bool Size(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty())
            return 0;
        return pq[0];
    }
    void insert(int val){
        pq.push_back(val);
        int ChildIndex = pq.size()-1;
        while(ChildIndex > 0){
            int ParentIndex = (ChildIndex - 1)/2;
            if(pq[ChildIndex] < pq[ParentIndex])
                swap(pq[ChildIndex], pq[ParentIndex]);
            else 
                break;
            ChildIndex = ParentIndex;
        }
    }

    int removeMin(){
        if(isEmpty())
            return 0;
        int val = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();
        int PI = 0;
        int LCI = 1;
        int RCI = 2;
        int MI = 0;
        while(LCI < pq.size()){
            if(pq[LCI] < pq[MI])
                MI = LCI;
            if(pq[RCI] < pq[MI])
                MI = RCI;
            if(MI == PI)
                break;
            swap(pq[PI], pq[MI]);
            PI = MI;
            LCI = 2 * PI + 1;
            RCI = 2 * PI + 2;
            MI = PI;
        }
        return val;
    }
};


int main(){
    MinHeap p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.Size()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;
}