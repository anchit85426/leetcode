class Solution {
public:
    unordered_map<int,unordered_map<int,unordered_map<int,double>>>mpp;
    int dx[8]={+1,+2,+2,+1,-1,-2,-2,-1};
    int dy[8]={-2,-1,+1,+2,-2,-1,+1,+2};
    double knightProbability(int n, int k, int row, int col) {
       if(mpp.count(row) and mpp[row].count(col) and mpp[row][col].count(k)) return mpp[row][col][k];
       if(row<0 or row>=n or col<0 or col>=n) return 0;
        if(k==0) return 1;
        double total=0;
        for(int i=0;i<8;i++){
            total+=knightProbability(n,k-1,row+dx[i],col+dy[i]);
        }
        total=total/8;
        mpp[row][col][k]=total;
        return mpp[row][col][k];
    }
};