//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>vis(1e5,0);
        int mod=1e5;
        queue<pair<int,int>>q;
        q.push({start,0});
        vis[start]=0;
        while(!q.empty()){
            int steps=q.front().second;
            int node=q.front().first;
            q.pop();
            for(auto it :arr){
                int x=(it*node)%mod;
                if(!vis[x]){
                    q.push({x,steps+1});
                    if(x==end){
                        return steps+1;
                    }
                    vis[x]=1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends