class Solution {
    void getCoordinate(int n,int s,int &row,int &col){
        row=n-1-(s-1)/n;
        col=(s-1)%n;
        if((n%2==1 and row%2==1) or (n%2==0 and row%2==0 )){
            col=n-1-col;
        }
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<pair<int,int>>q;
        vector<bool>seen(n*n+1,false);
        q.push({1,0});
        seen[1]=true;
        while(!q.empty()){
            auto it =q.front();
            int s=it.first;
            int cost=it.second;
            int row,col;
            q.pop();
            if(s==n*n){
                return cost;
            }
            for(int i=1;i<=6 and s+i<=n*n;i++){
                getCoordinate(n,i+s,row,col);
                int news=board[row][col]==-1?s+i:board[row][col];
                if(seen[news]==false){
                    seen[news]=true;
                    q.push({news,cost+1});
                }
            }
            
                
        }
        return -1;
    }
};