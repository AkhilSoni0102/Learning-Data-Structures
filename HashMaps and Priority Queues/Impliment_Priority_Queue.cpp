#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:
    PriorityQueue(){

    }

    int getSize(){
        return pq.size();
    }
    int isEmpty(){
        return pq.size() == 0;
    }
    int getMin(){
        if(isEmpty())
            return 0;
        return pq[0];
    }    

    void insert(int Value){
        pq.push_back(Value);
        int childIndex = pq.size()-1;
        // up Heapify
        while(childIndex > 0)
        {
            int parentIndex = (childIndex-1)/2;
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
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        // down heapify 
        int PI = 0;
        int LCI = 2*PI + 1;
        int RCI = 2*PI + 2;
        int MI = PI;

        while(LCI < pq.size()){
            MI = PI;
            if(pq[LCI] < pq[MI])
                MI = LCI;
            if(RCI < pq.size() && pq[RCI] < pq[MI])
                MI = RCI;
            if(MI == PI)
                break;
            swap(pq[MI],pq[PI]);
            
            PI = MI;
            LCI = 2*PI + 1;
            RCI = 2*PI + 2;
        }
        return ans;
    }
};

int main(){
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;
}