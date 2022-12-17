class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,0-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int row=it.second.first;
            int col=it.second.second;
            int max_path_diff=it.first;
            if(row==n-1 and col==m-1){
                return dis[n-1][m-1];
            }
            for(int i=0;i<4;i++){
                int newx=row+dx[i];
                int newy=col+dy[i];
                if(newx>=0 and newx<n and newy>=0 and newy<m){
                    int newEffort=max(abs(heights[newx][newy]-heights[row][col]),max_path_diff);
                    if(newEffort<dis[newx][newy]){
                        dis[newx][newy]=newEffort;
                        pq.push({newEffort,{newx,newy}});
                    }
                }
            }
            
        }
        return 0;
    }
};