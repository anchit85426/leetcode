class Solution {
    int time=0;
    void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&t){
        time+=t[node];
        for(auto it:adj[node]){
            if(par==it) continue;
            dfs(it,node,adj,t);
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& t) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(i==headID) continue;
            adj[manager[i]].push_back(i);
            
          
        }
       queue<pair<int,int>>q;
        q.push({headID,0});
        
        while(!q.empty())
        {
            int sq=q.size();
            
            while(sq--){
                int node=q.front().first;
                int timeq=q.front().second;
                q.pop();
               
                for(auto it:adj[node]){
                    q.push({it,timeq+t[node]});
                    time=max(time,timeq+t[node]);
                }
            }
          
        }
        return time;
    }      
};