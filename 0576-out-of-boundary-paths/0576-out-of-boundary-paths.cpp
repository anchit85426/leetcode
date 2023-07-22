class Solution {
    unordered_map<int,unordered_map<int,unordered_map<int,int>>>mpp;
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int mod=1e9+7;
    int findPaths(int n, int m, int k, int row, int col) {
        if(mpp.count(row) and mpp[row].count(col) and mpp[row][col].count(k)) return mpp[row][col][k];
        if(row<0 or row>=n or col<0 or col>=m ) return 1;
        if(k==0) return 0;
        int total=0;
        for(int i=0;i<4;i++){
            total=(total+findPaths(n,m,k-1,row+dx[i],col+dy[i]))%mod;
        }
        mpp[row][col][k]=total;
        return mpp[row][col][k];
    }
};