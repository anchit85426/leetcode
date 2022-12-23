class Solution {
    vector<unordered_set<int>>adj;
    vector<int>count;
    vector<int>res;
    public :
        void dfs(int root,int parent){
        for(auto it :adj[root]){
            if(it==parent){
                continue;
            }
            dfs(it,root);
            count[root]+=count[it];
            res[root]+=res[it]+count[it];
            
        }
    }
    void dfs2(int root,int parent){
        for(auto it :adj[root]){
            if(it==parent){
                continue;
            }
           
            res[it]=res[root]-count[it]+(count.size()-count[it]);
             dfs2(it,root);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n,0);
        count.resize(n,1);
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        dfs(0,-1);
        dfs2(0,-1);
        return res;
        
    }
};