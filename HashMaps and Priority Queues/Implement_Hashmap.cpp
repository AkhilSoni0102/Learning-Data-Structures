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
        for(int i = 0; i < numBuckets;i++)
            delete buckets[i];
        delete [] buckets;
    }

    int size(){
        return count;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head -> key == key){
                return head -> value;
            }
            head = head -> next;
        }
        return 0;

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
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i = 0; i < 2*numBuckets;i++)
            buckets[i] = NULL;
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i = 0;i < oldBucketSize;i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head -> key;
                V value = head -> value;
                insert(key, value);
                head = head -> next;
            }
        }
        for(int i = 0; i < oldBucketSize;i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }


    public:
    double getLoadFactor(){
        return (1.0 * count)/ numBuckets;
    }
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return ;
            }
            head = head -> next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* Node = new MapNode<V>(key, value);
        Node->next = head;
        buckets[bucketIndex] = Node;
        count++;
        double LoadFactor = (1.0 * count)/ numBuckets;
        if(LoadFactor > 0/7)
            rehash();
    }

    V remove(string key){
        int BucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[BucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head -> key == key){
                if(prev == NULL){
                    buckets[BucketIndex] = head -> next;                    
                }
                else{
                    prev -> next = head -> next;
                }
                head -> next = NULL;
                V Value = head -> value;
                delete head;
                count--;
                return Value;    
            }
            prev = head;
            head = head -> next;
        }
        return 0;
    }
};


int main(){
    ourmap<int> map;
    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string key ="abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout<<map.getLoadFactor()<<endl;
    }


    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key << ": "<< map.getValue(key)<<endl;
    }
    cout<<map.size()<<endl;
}