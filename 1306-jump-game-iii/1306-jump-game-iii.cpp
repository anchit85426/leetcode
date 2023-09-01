class Solution {
    vector<bool>dp;
    bool solve(vector<int>&arr,int idx){
          if(idx<0 or idx>=arr.size()){
            return false;
        }
        if(dp[idx]==true){
            return false;
        }
        if(arr[idx]==0){
            return true;
        }
      
        dp[idx]=true;
    
        return solve(arr,arr[idx]+idx)|| solve(arr,idx-arr[idx]);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        dp.resize(n+1,false);
        return solve(arr,start);
    }
};