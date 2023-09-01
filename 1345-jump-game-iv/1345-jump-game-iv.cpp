class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int>q;
        int ans=0;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                 q.pop();
                if(node==n-1){
                    return ans;
                }
               
                if(node+1<n and !vis[node+1]){
                    q.push(node+1);
                    vis[node+1]=1;
                }
                if(node-1>=0 and !vis[node-1]){
                    q.push(node-1);
                    vis[node-1]=1;
                }
                vector<int>&v=mpp[arr[node]];
                for(auto &it:v){
                    
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                        
                    }
                }
                v.clear();
              
            }
            ans++;
        }
        return 0;
    }
};