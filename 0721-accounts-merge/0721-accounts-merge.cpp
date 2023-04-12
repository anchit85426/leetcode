class DisjointSet {
public:    
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n+1);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
           for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }
                else{
                    ds.unionBySize(i,mpp[accounts[i][j]]);
                }
            }
        }
        vector<string>merged[n];
        for(auto it :mpp){
            string  s=it.first;
            int node=it.second;
            int p= ds.findUPar(node);
            
            merged[p].push_back(s);
        }
        
        vector<vector<string>>ans;
        int i=0;
     
        for(int i=0;i<n;i++){
            if(merged[i].size()==0){
              
                continue;
            }
            vector<string>x;
            sort(merged[i].begin(),merged[i].end());
            x.push_back(accounts[i][0]);
            for(auto it :merged[i]){
               
                x.push_back(it);
            }
        
            ans.push_back(x);
           
        }
     
        return ans;
    }
};