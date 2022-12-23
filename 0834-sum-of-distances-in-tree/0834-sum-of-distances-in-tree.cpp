class Solution {
    vector<unordered_set<int>>adj;
    public :
        void dfs(int root,int parent,vector<int>&count,vector<int>&res){
        for(auto it :adj[root]){
            if(it==parent){
                continue;
            }
            dfs(it,root,count,res);
            count[root]+=count[it];
            res[root]+=res[it]+count[it];
            
        }
    }
    void dfs2(int root,int parent,vector<int>&count,vector<int>&res,int n){
        for(auto it :adj[root]){
            if(it==parent){
                continue;
            }
           
            res[it]=res[root]-count[it]+(n-count[it]);
             dfs2(it,root,count,res,n);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>res(n,0);
        vector<int>count(n,1);
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        dfs(0,-1,count,res);
        dfs2(0,-1,count,res, n);
        return res;
        
    }
};