class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int ans=0;
        for(auto row :grid){
            int index=upper_bound(row.begin(),row.end(),0,greater<int>())-row.begin();
            ans+=(m-index);
        }
        return ans;
    }
};