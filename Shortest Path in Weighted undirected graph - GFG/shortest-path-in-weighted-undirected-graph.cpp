//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        for(auto it :edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        vector<int>dis(n+1,1e9),parent(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //{dist,node};
        dis[1]=0;
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        pq.push({0,1});
        while(!pq.empty()){
          int dist=pq.top().first;
          int node=pq.top().second;
          pq.pop();
          for(auto it :adj[node]){
             
              if(dis[it.first]>dist+it.second){
                    dis[it.first]=dist+it.second;
                    parent[it.first]=node;
                    pq.push({dis[it.first],it.first});
              }
          }
        }
        if(dis[n]==1e9) return {-1};
        vector<int>path;
        path.push_back(n);
        
        
        int x=parent[n];
        while(x!=1){
           path.push_back(x);
            x=parent[x];
        }
        
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends