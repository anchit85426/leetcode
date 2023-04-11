class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int>indegree(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        vector<vector<int>>dp(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i][colors[i]-'a']=1;
            }
        }
       
        int countnodes=0;
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            countnodes++;
            ans=max(ans,dp[node][colors[node]-'a']);
            for(auto it :adj[node]){
                for(int i=0;i<26;i++){
                    dp[it][i]=max(dp[it][i],dp[node][i]+(i==colors[it]-'a'));
                    
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
       
        if(countnodes!=n){
            return -1;
        }
        return ans;
    }
};