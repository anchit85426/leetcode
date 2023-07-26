class LockingTree {
public:
    vector<vector<int>>v; // tree
    //v[i][0]==parent[i];
    // v[i][1]==-1 unlocked
    // v[i][1]==x locked by x
     // descedabt means all the path from the child to the leaf node or the full subtree
    // ancestor means partent or parent of parent .....
    map<int,vector<int>>descendant;
    LockingTree(vector<int>& parent) {
        descendant.clear();
        int n=parent.size();
        v.resize(n,vector<int>(2,-1));
        v[0][0]=-1;
        for(int i=1;i<n;i++){
            v[i][0]=parent[i];
            descendant[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(v[num][1]!=-1) return false;
        
        v[num][1]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(v[num][1]!=user) return false;
        v[num][1]=-1;
        return true;
    }
    bool checkDescendant(int num){
         for(auto &it:descendant[num]){
             if(v[it][1]!=-1){
                 return true;
             }
             else{
                 if(checkDescendant(it)==true){
                     return true;
                 }
             }
         }
        return false;
    }
    bool lockedAncestors(int num){
        // none of the Ancestors should be locked
        // if locked return false;
        if(num==-1) return true;
        if(v[num][1]!=-1){
            return false;
        }
        return (v[num][1]==-1) && lockedAncestors(v[num][0]);
        
        
        
    }
    void unlockDes(int num){
        for(auto &it:descendant[num]){
            v[it][1]=-1;
            unlockDes(it);
        }
    }
    bool upgrade(int num, int user) {
        if(v[num][1]!=-1) return false;
        
        bool x=checkDescendant(num);
        if(x==false){
            return false;
        }
        bool y=lockedAncestors(v[num][0]);
        
        if(y==false ){
            return false;
        }
        // unlock descedant
        unlockDes(num);
        v[num][1]=user;
        return true;
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */