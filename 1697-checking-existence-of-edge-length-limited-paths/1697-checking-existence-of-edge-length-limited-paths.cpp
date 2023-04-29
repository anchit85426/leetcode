class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
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
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        DisjointSet st(n+1);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](auto &l,auto &r) {return l[2]<r[2];});
        sort(edgeList.begin(),edgeList.end(),[](auto &l,auto &r){return l.back()<r.back();});
       
        
         int i=0;
        vector<bool>result(queries.size());
        for(auto &it :queries){
            while(i<edgeList.size() and edgeList[i][2]<it[2]){
                st.unionByRank(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            if(st.findUPar(it[0])==st.findUPar(it[1])){
                result[it.back()]=1;
            }
            else{
                result[it.back()]=0;
            }
        }
        return result;
    }
};