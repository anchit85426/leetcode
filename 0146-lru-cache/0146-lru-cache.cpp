class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    int cap;
    unordered_map<int,node*>mpp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    void addnode(node *newnode){
        node *temp=head->next;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
        head->next=newnode;
    }
    void deletenode(node *delnode){
        node *prevnode=delnode->prev;
        node *nextnode=delnode->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node* res_node=mpp[key];
            int res=res_node->val;
            mpp.erase(key);
            deletenode(res_node);
            addnode(res_node);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // already present
        if(mpp.find(key)!=mpp.end()){
            node* exisitingnode=mpp[key];
            
            mpp.erase(key);   
            deletenode(exisitingnode);
        }
        // if full
        if(mpp.size()==cap){
            // delete last node
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */