//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    vector<vector<int>>adj;
    vector<int>vis,par,pathVis;
    long long int ans=-1;
  void dfs(int node,int p,int sum){
     
      vis[node]=1;
      pathVis[node]=sum;
      par[node]=p;
      for(auto  it:adj[node]){
          if(!vis[it]){
              dfs(it,node,sum+it);
          }
          else{
              if(pathVis[it]!=-1){
                  
                  long long int sum=pathVis[node]-pathVis[it]+it;
                 ans=max(ans,sum);
                  }
             
          }
        
      }
      pathVis[node]=-1;
  }
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    adj=vector<vector<int>>(N);
    vis=vector<int>(N);
    par=vector<int>(N);
    pathVis=vector<int>(N);
    int i=0;
    for(auto it:Edge){
       if(it!=-1){
           adj[i].push_back(it);
       }
       i++;
    }
    for(int i=0;i<N;i++){
        if(!vis[i]){
            dfs(i,-1,i);
        }
    }
    return ans;
      
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends