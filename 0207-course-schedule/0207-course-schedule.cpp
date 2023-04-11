class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& p) {
         int n=num;
        vector<int>indegree(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto it :p){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
               for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
               
            }
        }
       
        int countnodes=0;
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            countnodes++;
         
            for(auto it :adj[node]){
                
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
       
      if(countnodes==n){
          return true;
      }
        else{
            return false;
        }
    }
};