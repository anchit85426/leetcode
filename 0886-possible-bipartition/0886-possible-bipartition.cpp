class Solution {
    private:
         bool dfs(int node,int col,vector<int>adj[],int colour[]){
        colour[node]=col;
        for(auto it :adj[node]){
            if(colour[it]==-1){
                
                if(dfs(it,!col,adj,colour)==false){
                    return false;
                }
            }
            else if(colour[it]==colour[node]){
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int V, vector<vector<int>>& dislikes) {
        int colour[V+1];
        vector<int>adj[V+1];
        for(auto it :dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
	    for(int i=1;i<=V;i++){
	        colour[i]=-1;
	    }
        for(int i=1;i<=V;i++){
        if(colour[i]==-1){
	        if(dfs(i,0,adj,colour)==false){
            
	                return false;
	        }   
        }
    }
	    return true;
    }
};