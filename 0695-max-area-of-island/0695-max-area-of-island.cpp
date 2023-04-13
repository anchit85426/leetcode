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
    private:
    bool isValid(int i,int j,int n,int m){
        return i>=0 and i<n and j>=0 and j<m;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        int count=0;
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==0 ) {
                    count++; continue;
                }
                int dx[]={-1,0,1,0};
                int dy[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int nrow=dx[i]+row;
                    int ncol=dy[i]+col;
                    if(isValid(nrow,ncol,n,m)){
                        if(grid[nrow][ncol]==1){
                            ds.unionBySize(nrow*m+ncol,row*m+col);
                        }
                    }
                }
            }
        }
        for(int row=0;row<n*m;row++){
            
            mx=max(mx,ds.size[ds.findUPar(row)]);
        }
        if(count==n*m) return 0;
        return mx;
    }
};