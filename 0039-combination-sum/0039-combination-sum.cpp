class Solution {
    vector<vector<int>>ans;
     void solve(int idx,vector<int>&candidates,int target,vector<int>&x){
         if(idx==candidates.size()){
         if(target==0){
            ans.push_back(x);
            
         }
              return ;
         }
         if(candidates[idx]<=target){
             x.push_back(candidates[idx]);
             solve(idx,candidates,target-candidates[idx],x);
             x.pop_back();
         }
         solve(idx+1,candidates,target,x);
     }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>x;
        
        solve(0,candidates,target,x);
       return ans; 
    }
};