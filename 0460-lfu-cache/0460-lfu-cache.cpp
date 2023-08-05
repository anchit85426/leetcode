struct Node{
    int key,value,cnt;
    Node * next;
    Node* prev;
    Node(int _key,int _val){
        key=_key;
        value=_val;
        cnt=1;
    }
    
};
struct List{
    int size;
    Node *head;
    Node *tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addfront(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
        size++;
        
    }
    void removeNode(Node* node){
        Node* nextnode=node->next;
        Node* prevnode=node->prev;
        nextnode->prev=prevnode;
        prevnode->next=nextnode;
        size--;
        
    }
};

class LFUCache {
public:
    map<int,Node*>keynode;
    map<int,List*>FreqListMap;
    int maxCacheSize;
    int minFreq;
    int curSize;
    LFUCache(int capacity) {
        maxCacheSize=capacity;
        minFreq=0;
        curSize=0;
    }
    void updateFreqListMap(Node* node){
        keynode.erase(node->key);
        FreqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq and FreqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHigherFrequency=new List();
        if(FreqListMap.find(node->cnt+1)!=FreqListMap.end()){
            nextHigherFrequency=FreqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFrequency->addfront(node);
        FreqListMap[node->cnt]=nextHigherFrequency;
        keynode[node->key]=node;
    }
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node *node=keynode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize==0){
            return;
        }
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else{
            if(maxCacheSize==curSize){
                List* list=FreqListMap[minFreq];
                keynode.erase(list->tail->prev->key);
               FreqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List* FreqList=new List();
            if(FreqListMap.find(minFreq)!=FreqListMap.end()){
                FreqList=FreqListMap[minFreq];
            }
            Node* node=new Node(key,value);
            FreqList->addfront(node);
            keynode[key]=node;
            FreqListMap[minFreq]=FreqList;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */