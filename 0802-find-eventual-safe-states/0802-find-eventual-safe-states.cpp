class Solution {
    private: 
        bool dfs(int node,vector<int> &vis,vector<int>& pathvis,vector<int>& check,vector<int>adj[]){
            vis[node]=1;
            pathvis[node]=1;
            check[node]=0;
            for(auto it :adj[node]){
                if(!vis[it]){
                    if(dfs(it,vis,pathvis,check,adj)==true){
                        check[node]=0;
                        return true;  
                    } 
                }   
                else if(pathvis[it]){
                    check[node]=0;
                    return true;
                }
            }
            check[node]=1;
            pathvis[node]=0;
            return false;
           
        }   
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>adj[N];
        for(int i=0;i<N;i++){
            for(auto it :graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> vis(N,0);
        vector<int> pathvis(N,0);
        vector<int> check(N,0);
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
        return ans;
        
    }
};