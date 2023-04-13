class NumMatrix {
    vector<vector<int>>sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        sums = vector<vector<int>>(n+1, vector<int>(m+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sums[i][j]=matrix[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return sums[row2][col2]-sums[row2][col1-1]-sums[row1-1][col2]+sums[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */