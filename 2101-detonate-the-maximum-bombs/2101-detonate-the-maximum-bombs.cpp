class Solution {
    void dfs(int node,vector<vector<int>>&adj,int &cnt,vector<int>&vis)
    {
        cnt++;
        for(auto it :adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,cnt,vis);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                long long int  dx=abs(bombs[i][0]-bombs[j][0]);
                 long long int  dy=abs(bombs[i][1]-bombs[j][1]);
                long long int dr=bombs[i][2];
                dr*=bombs[i][2];
                if(dx*dx+dy*dy<=dr){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt=0;
                vector<int>vis(n,0);
                vis[i]=1;
                dfs(i,adj,cnt,vis);
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};