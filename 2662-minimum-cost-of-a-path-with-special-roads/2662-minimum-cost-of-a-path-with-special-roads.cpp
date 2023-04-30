class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoad) {
        int n=specialRoad.size();
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            dist[i]=abs(start[0]-specialRoad[i][0])+abs(start[1]-specialRoad[i][1])+specialRoad[i][4];
            pq.push({dist[i],i});
        }
        int ans=abs(start[0]-target[0])+abs(start[1]-target[1]);
        while(!pq.empty()){
            auto d=pq.top().first;
            auto i=pq.top().second;
            pq.pop();
            ans=min(ans,d+abs(specialRoad[i][2]-target[0])+abs(specialRoad[i][3]-target[1]));
            for(int j=0;j<n;j++){
                int d1=abs(specialRoad[i][2]-specialRoad[j][0])+abs(specialRoad[i][3]-specialRoad[j][1])+specialRoad[j][4];
                if(d1+d<dist[j]){
                    dist[j]=d1+d;
                    pq.push({dist[j],j});
                }
                    
            }
            
        }
        return ans;
    }
};