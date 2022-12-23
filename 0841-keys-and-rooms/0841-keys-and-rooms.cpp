class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n=rooms.size();
        q.push(0);
        int x=0;
        vector<int>vis(n,0);
        while(!q.empty()){
            x++;
            
            int node=q.front();
            vis[node]=1;
            q.pop();
            for(auto it :rooms[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        
        return x==n;
    }
};