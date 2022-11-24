//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
        private: 
        bool dfs(int node,int vis[],int pathvis[],int check[],vector<int>adj[]){
            vis[node]=2;
            check[node]=0;
            for(auto it :adj[node]){
                if(!vis[it]){
                    if(dfs(it,vis,pathvis,check,adj)==true){
                        check[node]=0;
                        return true;  
                    } 
                }   
                else if(vis[it]==2){
                    
                    check[node]=0;
                    return true;
                }
            }
            check[node]=1;
            vis[node]=1;
            pathvis[node]=0;
            return false;
           
        } 
  public:
    vector<int> eventualSafeNodes(int N, vector<int> adj[]) {
        // code here
       // if cycel is there and it would not reach ther terminal node
       // ther node that has outgoing edge to cycle containing node would also not reach the terminal node
       // pathvis would be 1 at last of cycle containing node
       
        int vis[N]={0};
        int check[N]={0};
        int pathvis[N]={0};
        vector<int>ans;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,check,adj);
                 
            }
        }
        for(int i=0;i<N;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        vector<int>ans2;
        for(int i=0;i<N;i++){
            if(vis[i]==1){
                ans2.push_back(i);
            }
        }
        return ans2;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends