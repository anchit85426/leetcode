class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it :redEdges){
            graph[it[0]].push_back({it[1],0});
        }
         for(auto it :blueEdges){
            graph[it[0]].push_back({it[1],1});
        }
        vector<int>dist(n,-1);
        vector<vector<int>> vis(n+1, vector<int>(3, 0));
        vis[0][0]=1;
        vis[0][1]=1;
        dist[0]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,-1}});// source,{dist,colour}
        while(!q.empty()){
            int node=q.front().first;
            int disti=q.front().second.first;
            int colour=q.front().second.second;
            q.pop();
            for(auto it :graph[node]){
                if(it.second!=colour and vis[it.first][it.second]==0){
                    if(dist[it.first]==-1)
                    {
                        dist[it.first]=1+disti;
                    }
                    q.push({it.first,{disti+1,it.second}});
                     vis[it.first][it.second]=1;
                }
            }
        }
        return dist;
    }
};