class Solution {
    vector<vector<int>>ans;
    void solve(int k,vector<int>&temp,int start,int n){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(start>n) return;
        for(int i=start;i<=n;i++){
          
                temp.push_back(i);
                solve(k-1,temp,i+1,n);
                temp.pop_back();
                
            }
        
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(k,temp,1,n);
        return ans;
    }
};