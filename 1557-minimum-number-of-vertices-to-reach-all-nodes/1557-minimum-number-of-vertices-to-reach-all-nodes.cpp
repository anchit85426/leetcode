class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>v(n,0);
        for(auto it :edges){
            v[it[1]]++;
        }
        int i=0;
        vector<int>ans;
        for(auto it :v){
            if(it==0){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};