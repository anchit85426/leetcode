class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int ans=0;
        int row=0;
        int col=m-1;
        while(row<n and col>=0){
            if(grid[row][col]<0){
                ans+=n-row;
                col--;
            }
            else{
                row++;
            }
        }
        return ans;
    }
};