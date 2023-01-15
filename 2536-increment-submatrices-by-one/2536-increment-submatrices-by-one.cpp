class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>v(n,vector<int>(n,0));
        for(auto it :queries){
            int row1=it[0];
            int col1=it[1];
            int row2=it[2];
            int col2=it[3];
            v[row1][col1]+=1;
            if(row1<n and col2+1<n) v[row1][col2+1]-=1;
            if(row2+1<n and col1<n) v[row2+1][col1]-=1;
            if(row2+1<n and col2+1<n) v[row2+1][col2+1]+=1;
        }
        
        for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            v[i][j]+=v[i][j-1];
            }
        }
        for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            v[i][j]+=v[i-1][j];
        }
   
    }
    return v;
    }
};