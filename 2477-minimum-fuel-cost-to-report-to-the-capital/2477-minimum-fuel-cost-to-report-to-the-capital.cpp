class Solution {
    long long ans=0;
    
    long long int dfs(int node,int par,vector<vector<int>>&adj,int s,int people=1){
        for(auto it :adj[node]){
            if(it==par) continue;
            if(it!=par){
                 people+=dfs(it,node,adj,s);
            }
            
        }
        if(node!=0){
            ans+=(s+people-1)/s;
        }
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>>adj(roads.size()+1);
        for(auto it :roads){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        
        dfs(0,-1,adj,seats);
        return ans;
    }
};