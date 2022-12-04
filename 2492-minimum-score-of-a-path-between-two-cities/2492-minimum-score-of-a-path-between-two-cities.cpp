class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(auto it :roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>vis(n+1);
        for(int i=1;i<=n;i++){
            vis[i]=0;
        }
        queue<int>q;
        vis[1]=1;
        q.push(1);
        int minimum_edge=INT_MAX;
        while(!q.empty()){
            int  node=q.front();
            q.pop();
            for(auto it :adj[node]){
                minimum_edge=min(minimum_edge,it.second);
                if(!vis[it.first]){
                    vis[it.first]=1;
                    q.push(it.first);
                }
            }
        }
        return minimum_edge;
        
    }
};