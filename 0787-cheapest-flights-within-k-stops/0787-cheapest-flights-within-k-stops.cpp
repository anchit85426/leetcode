class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            q.pop();
            if(steps>k){
                break;
            }
            for(auto it :adj[node]){
                if(dis[it.first]>dist+it.second){
                    dis[it.first]=dist+it.second;
                    q.push({steps+1,{it.first,dis[it.first]}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
    
};