class Solution {
    void dfs(int node1,vector<int>&dist1,vector<int>edges){
        
        dist1[node1]=0;
        int x=1;
        int flag=1;
        while(flag==1){
            if(edges[node1]==-1){
                break;
            }
            if(dist1[edges[node1]]!=-1){
                break;
            }
          
           dist1[edges[node1]]=x;
            
            node1=edges[node1];
            
            x++;
            if(node1==-1){
                flag=0;
                break;
            }
            
       }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int n=edges.size();
            
        
        vector<int>dist1(n,-1);
        vector<int>dist2(n,-1);
        dist1[node1]=0;
        dist2[node2]=0;
       if(edges[node1]!=-1) dfs(node1,dist1,edges);
        
       if(edges[node2]!=-1) dfs(node2,dist2,edges);
        int ans=-1;
        int MAX_DIST=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(dist1[i]==-1 or dist2[i]==-1){
                continue;
            }
            if(MAX_DIST>max(dist1[i],dist2[i])){
                MAX_DIST=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        if(ans==1e9) return -1;
        return ans;
            
    }
};