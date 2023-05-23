class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++){
            if(!color[i]){
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it :graph[node]){
                        if(!color[it]){
                            color[it]=-color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]){
                            return false;
                        }
                    }
                }
            }
        } 
        return true;
    }
};