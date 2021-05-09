#include<string> 
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
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    public: 
    ourmap(){
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
    }

    ~ourmap(){
        for(int i = 0; i < numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    int size(){
        return count;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* Head = buckets[bucketIndex];
        while(Head != NULL){
            if(Head -> key == key){
                return Head -> value;
            }
            Head = Head -> next;
        }
        return 0;
    }
    private: 
    int getBucketIndex(string key){
        int hashCode = 0;
        int currCoeff = 1;
        for(int i = key.length()-1; i >= 0;i--){
            hashCode += key[i] * currCoeff;
            hashCode %= numBuckets;
            currCoeff *= 37;
            currCoeff %= numBuckets;
        }

        return hashCode % numBuckets;
    }

    public:
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* Head = buckets[bucketIndex];
        while(head != NULL){
            if(head -> value == value){
                head->value = value;
                return ;
            }
            head = head -> next;
        }
        Head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node -> next = Head;
        buckets[bucketIndex] = node;
        count++;
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* Head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(Head != NULL){
            if(Head -> key == key){
                if(prev = NULL){
                    buckets[bucketIndex] = Head -> next;
                }
                else 
                    prev->next = Head -> next;
                V value;
                count--;
                head -> next = NULL;
                delete head;
                return value;
            }
            prev = Head;
            Head = Head -> next;
        }
        return 0;

    }


};