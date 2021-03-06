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
    int numBuckets;

    public:
    ourmap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0;i < numBuckets;i++)
            buckets[i] = NULL;
    }
    ~ourmap(){
        for(int i = 0;i < numBuckets;i++)
            delete buckets[i];
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
    double getLoadFactor(){
        return (1.0 * count)/numBuckets;
    }
    void rehash(){
        MapNode<V>** temp = buckets;
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets;i++)
            buckets[i] = NULL;
        
        for(int i = 0;i < oldBucketSize;i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head -> key;
                V value = head -> value;
                insert(key, value);
                head = head -> next;
            }
        }

        for(int i = 0;i < oldBucketSize;i++)
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
        double LF = (1.0*count)/numBuckets;
        if(LF > 0.7){
            rehash();
        }
    }

    V remove(string key){
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
                int value = head -> value;
                count--;
                delete head;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};


int main(){
    ourmap<int> map;
    for(int i = 0;i < 10;i++){
        char c = 'c' + i;
        string key = "abc"; 
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
    }
    cout<<map.size();

    for(int i = 0;i < 10;i++){
        char c = 'c' + i;
        string key = "abc"; 
        key = key + c;
        cout<<map.remove(key)<<endl;
    }
}