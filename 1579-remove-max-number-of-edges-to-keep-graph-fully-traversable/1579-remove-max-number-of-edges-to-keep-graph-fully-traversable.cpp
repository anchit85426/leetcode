class DisjointSet {
    
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
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
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet a(n+1);
        DisjointSet b(n+1);
        int ans=0;
        for(auto it :edges){
            if(it[0]!=3) continue;
            int u=it[1];
            int v=it[2];
            if(a.findUPar(u)==a.findUPar(v)){
                ans++;
                continue;
            }
            a.unionBySize(u,v);
             b.unionBySize(u,v);
            
        }
        for(auto it :edges){
            if(it[0]==1){
                int u=it[1];
                 int v=it[2];
                if(a.findUPar(u)==a.findUPar(v)){
                    ans++;
                    continue;
            }
            a.unionBySize(u,v);
 
            }
            else if(it[0]==2){
                 int u=it[1];
                 int v=it[2];
                if(b.findUPar(u)==b.findUPar(v)){
                    ans++;
                    continue;
            }
            b.unionBySize(u,v);
            }
        }
         for(int i=1;i<=n;i++){
                if(a.findUPar(i)==i){
                    if(a.size[i]!=n){
                        return -1;
                    }
                }
            }
        
        for(int i=1;i<=n;i++){
            if(b.findUPar(i)==i){
                if(b.size[i]!=n){
                    return -1;
                }
            }
        }
        return ans;
    }
};