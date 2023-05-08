class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        int row=0,col=0;
        while(row<n and col<n){
            sum+=mat[row][col];
            row++;
            col++;
        }
        row=0,col=n-1;
        while(row<n and col>=0){
            sum+=mat[row][col];
            row++;
            col--;
        }
        if(n%2==1){
            sum-=mat[n/2][n/2];
        }
        return sum;
    }
};