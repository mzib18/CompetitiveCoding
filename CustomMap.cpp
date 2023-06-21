#include<string>
using namespace std;
template <typename V>
class mapNode{
public:
    string key;
    V value;
    mapNode* next;
    mapNode(string key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};
template <typename V>
class CustomMap{
    mapNode<V>** buckets;
    int c;
    int numBuckets;

public:
    CustomMap(){
        c=0;
        numBuckets = 5;
        buckets = new mapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++)buckets[i]=NULL;
    }
    ~CustomMap(){
        for(int i=0;i<numBuckets;i++)delete buckets[i];
        delete [] buckets;
    }
    int size(){return c;}
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head !=NULL){
            if(head->key == key)return head->value;
            head=head->next;
        }
        return 0;
    }
private:
    int getBucketIndex(string key){
        int hashcode=0;
        int curr=1;
        for(int i=key.length()-1;i>=0;i--){
            hashcode += key[i] * curr;
            hashcode = hashcode % numBuckets;
            curr*=37;
            curr = curr % numBuckets;
        }
        return hashcode % numBuckets;
    }
    void rehash(){
        mapNode<V>** temp = buckets;
        buckets = new mapNode<V>*[2 * numBuckets];
        for(int i=0; i<2*numBuckets; i++){
            buckets[i]=NULL;
        }
        int old = numBuckets;
        numBuckets *=2;c=0;
        for(int i=0;i<old;i++){
            mapNode<V>* head = temp[i];
            while(head !=NULL){
                string key = head->key;
                V value = head->value;insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<old;i++)delete temp[i];
        delete [] temp;
    }
public:
    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V>* node = new mapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex]=node;c++;
        double loadf = (1.0*c)/numBuckets;
        if(loadf > 0.7){
            rehash();
        }
    }
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        mapNode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL)buckets[bucketIndex] = head->next;
                else prev->next = head->next;
                V value = head->value;
                head->next = NULL;
                delete head;c--;
                return value;
            }
            prev = head;
            head=head->next;
            head = head->next;
        }
        return 0;
    }
};
