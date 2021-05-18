#include<bits/stdc++.h>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value){
        this -> value = value;
        this -> key = key;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numbuckets;

    ourmap(){
        count = 0;
        numbuckets = 5;
        buckets = new MapNode<V>*[numbuckets];
        for(int i = 0;i < numbuckets;i++)
            buckets[i] = NULL;
    }

    ~ourmap(){
        for(int i = 0;i < numbuckets;i++)
            delete buckets[i];
        delete [] buckets;
    }

    int getSize(){
        return count;
    }

    int getBucketIndex(string key){
        int hashCode = 0;
        int currCoeff = 1;
        for(int i = key.length()-1;i >= 0;i--){
            hashCode += key[i] * currCoeff;
            hashCode %= numbuckets;
            currCoeff *= 37;
            currCoeff %= numbuckets;
        }
        return hashCode % numbuckets;
    }
    
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(string);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head -> key == key){
                head -> value = value;
                return ;
            }
            head = head -> next;
        }
        MapNode<V>* node = new MapNode<V>(key, value);
        buckets[bucketIndex] = node;
    }

};





/*#include<bits/stdc++.h>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value){
        this -> key = key;
        this -> value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template<typename V>
class ourmap{
    public:
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    ourmap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0;i < numBuckets;i++)   
            buckets[i] = NULL;
    }

    ~ourmap(){
        for(int i = 0;i < numBuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    private: 
    int getBucketIndex(string key){
        int hashCode = 0;
        int currCoeff = 1;
        for(int i = key.length()-1;i>=0;i--){
            hashCode += key[i]*currCoeff;
            hashCode %= numBuckets;
            currCoeff *= 37;
            currCoeff %= numBuckets;
        }
        return hashCode % numBuckets;
    }
    void rehash(){
        MapNode<V>** temp = buckets;
        count = 0;
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets;i++)
            buckets[i] = NULL;
        for(int i = 0; i < oldBucketSize;i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head ->key;
                V value = head -> value;
                insert(key, value);
                head = head -> next;
            }
        }

        for(int i = 0; i < oldBucketSize;i++)
            delete temp[i];
        delete [] temp;
    }


    public:
    int size(){
        return count;
    }
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head -> key == key)
                return head -> value;
            head = head -> next;
        }
        return 0;

    }

    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head -> key == key){
                head -> value = value;
                return ;
            }
            head = head -> next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* Node = new MapNode<V>(key, value);
        Node -> next = head;
        buckets[bucketIndex] = Node;
        count++;
        double LoadFactor = (1.0 * count) / numBuckets;
        if(LoadFactor > 0.7)
            rehash();

    }

    V removeElement(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head -> key == key){
                if(prev == NULL)
                    buckets[bucketIndex] = head -> next;
                else 
                    prev -> next = head -> next;
                head -> next = NULL;
                int Value = head -> value;
                delete head;
                count--;
                return Value;
            }
            prev = head ;
            head = head -> next;
        }
        return 0;

    }

};


class PriorityQueue{
    public:
    vector<int> pq;

    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    void insert(int value){
        pq.push_back(value);
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex - 1)/2;
        while(parentIndex > 0){
            if(pq[childIndex] < pq[parentIndex]){
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
                break;
            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        }
    }

    int Size(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty())
            return 0;
        return pq[0];
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
            if(RCI < pq.size() && pq[RCI] < pq[MI])
                MI = RCI;
            if(PI == MI)
                break;
            swap(pq[MI], pq[PI]);
            PI = MI;
            LCI = 2*PI + 1;
            RCI = 2*PI + 2;
            MI = PI;
        }
        return value;
    }



};


int main(){
    cout<<"HashMap: "<<endl;
    ourmap<int> map;
    for(int i = 0;i < 10;i++){
        char c = '0'+i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        map.insert(key, value);
    }

    for(int i = 0;i < 10;i++){
        char c = '0'+i;
        string key = "abc";
        key = key + c;
        cout<<"Key: "<<key<<" Value: "<<map.removeElement(key)<<endl;
    }   
    for(int i = 0; i < 15;i++)
        cout<<"-";
    cout<<endl;
    cout<<"PriorityQueue: "<<endl;

    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(14);
    p.insert(33);
    p.insert(23);
    p.insert(55);
    p.insert(20);

    cout<<p.Size()<<endl;

    while(!p.isEmpty())
        cout<<p.removeMin()<<" ";

}*/