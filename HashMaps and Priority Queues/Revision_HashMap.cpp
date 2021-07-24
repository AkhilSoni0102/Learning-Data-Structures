#include<bits/stdc++.h>
using namespace std;

template<typename V>
class MapNode{
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
    int numBuckets;
    int count;

    MapNode(){
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0;i < numBuckets;i++){
            buckets[i] = NULL;
        }
    }

    int getBucketIndex(string key){
        int hashCode = 0;
        int currCoeff = 1;
        for(int i = key.length()-1;i>=0;i--){
            hashCode += currCoeff*key[i];
            hashCode %= numBuckets;
            currCoeff *= 37;
            currCoeff %= numBuckets;
        }
        return hashCode % numBuckets;
    }

    void insert(string key, value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head -> key == key){
                head -> value = value;
                return ;
            }
            head = head -> next;
        }
        MapNode<V>* New = new MapNode<V>(key, value);
        New -> next = head;
        bucket[bucketIndex] = New;
        return ;
    }

    int remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if()
        }
    }
}

/*#include<bits/stdc++.h>
using namespace std;

template<typename V>
class MapNode{
    public:
    V value;
    string key;
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
        numBuckets = 10;
        count = 0;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0;i < numBuckets;i++)
            buckets[i] = NULL;
    }

    ~ourmap(){
        for(int i = 0 ;i < numBuckets;i++)
            delete buckets[i];
        delete [] buckets;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        int oldBucketsSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0;i < numBuckets;i++)
            buckets[i] = NULL;
        for(int i = 0;i < oldBucketsSize;i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head -> key;
                V value = head -> value;
                insert(key, value);
                head = head -> next;
            }
        }
        for(int i = 0;i < oldBucketsSize;i++){
            delete temp[i];
        }
        delete [] temp;
    }

    int getBucketIndex(string key){
        int hashCode = 0;
        int currCoeff = 1;
        for(int i = key.length()-1 ;i>=0 ;i--){
            hashCode += key[i] * currCoeff;
            hashCode %= numBuckets;
            currCoeff *= 37;
            currCoeff %= numBuckets;
        }
        return hashCode % numBuckets;
    }

    int Size(){
        return count;
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
        MapNode<V>* node = new MapNode<V>(key, value);
        head = buckets[bucketIndex];
        buckets[bucketIndex] = node;
        node -> next = head;
        count++;
        double loadFactor = count * (1.0) / numBuckets;
        if(loadFactor > 0.7){
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
                V val = head -> value;
                head -> next = NULL;
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head -> next;
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
    cout<<map.Size()<<endl;

    for(int i = 0;i < 10;i++){
        char c = 'c' + i;
        string key = "abc"; 
        key = key + c;
        cout<<map.remove(key)<<endl;
    }
}*/