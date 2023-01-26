class Solution {
    int dfs(int node,int par,vector<int>adj[],vector<bool>hasApple){
        int time=0;
        for(auto it :adj[node]){
            if(it==par) continue;
            int time_from_child=dfs(it,node,adj,hasApple);
            
            if(time_from_child>0 or hasApple[it]==true){
                time+=time_from_child+2;
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n+1];
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};