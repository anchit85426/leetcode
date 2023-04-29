class DisjointSet {
    vector<int> rank, parent, size;
public:
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
    private:
    bool poss(string &a,string &b){
        int n=a.size();
        int k=0;
        for(int i=0;i<n;i++){
           
            if(a[i]!=b[i]){
                k+=1;
            }
             if(k>2) return false;
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet st(n+1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(poss(strs[i],strs[j])){
                    
                    st.unionBySize(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.findUPar(i)==i){
                ans++;
            }
        }
        return ans;
    }
};