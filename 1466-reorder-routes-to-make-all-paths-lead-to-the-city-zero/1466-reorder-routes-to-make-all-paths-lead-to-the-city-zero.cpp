class Solution {
    int ans=0;
    void dfs(int node,vector<vector<int>>&adj,vector<vector<int>>&back,vector<int>&vis){
        
        for(auto it :adj[node]){
            if(!vis[it]){
                ans++;
                vis[it]=1;
                dfs(it,adj,back,vis);
            }
        }
        for(auto it:back[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,back,vis);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n+1);
        vector<vector<int>>back(n+1);
        for(auto it :connections){
            adj[it[0]].push_back(it[1]);
            back[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        vis[0]=1;
        dfs(0,adj,back,vis);
        return ans;
    }
};