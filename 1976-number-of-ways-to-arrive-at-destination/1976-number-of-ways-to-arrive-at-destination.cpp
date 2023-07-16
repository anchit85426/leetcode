class Solution {
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long int ,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
        pq.push({0,0});
        
        vector<long long int >dist(n,2e16);
        dist[0]=0;
        vector<long long int >ways(n,0);
        ways[0]=1;
        long long  int mod = (int)(1e9 + 7);
        vector<vector<pair<long long int ,long long int >>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        while(!pq.empty()){
            long long int node=pq.top().second;
            long long int wt=pq.top().first;
            pq.pop();
           
            
            for(auto it :adj[node]){
               
               if(it.second+wt<dist[it.first]){
                   dist[it.first]=it.second+wt;
                   ways[it.first]=ways[node];
                   pq.push({dist[it.first],it.first});
               }
                else if(it.second+wt==dist[it.first]){
                    ways[it.first]=(ways[it.first]+ways[node]+mod)%mod;
                }
                
                }
            
            
        }
        return ways[n-1]%mod;
    }
};