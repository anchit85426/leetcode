class Solution {
    private:
    bool dfs(int node,int destionation,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it :adj[node]){
           
            if(it==destionation){
                vis[destionation]=1;
                return true;
            }
            if(!vis[it]){
               if( dfs(it,destionation,adj,vis)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n+1,0);
        vector<int>adj[n+1];
        if(source==destination){
            return true;
        }
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
       return   dfs(source,destination,adj,vis);
      
    }
};