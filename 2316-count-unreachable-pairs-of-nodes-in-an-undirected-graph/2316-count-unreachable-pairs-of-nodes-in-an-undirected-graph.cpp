class Solution {
    vector<int>ans;
    int c=1;
    void dfs(int n,vector<int>&vis,vector<vector<int>>&adj){
        for(auto it :adj[n]){
            if(!vis[it]){
                vis[it]=1;
                c++;
                dfs(it,vis,adj);
                
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                // cout<<i<<endl;
                vis[i]=1;
                dfs(i,vis,adj);
                // cout<<c<<endl;
                ans.push_back(c);
                c=1;
            }
        }
        long long f=0;
        long long m=0;
        if(ans.size()==1){
            return 0;
        }
        for(auto it :ans){
            m+=it;
        }
        // for(auto it :ans){
        //     cout<<it<<" ";
        // }
        // // cout<<endl;
        // // cout<<m<<endl;
         for(auto it :ans){
            m-=it;
            // cout<<it<<endl;
            // cout<<m<<endl;
            f+=it*(m);
       
         //   cout<<f<<endl;
        }
        return f;
    }
};