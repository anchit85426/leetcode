class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>s;
        int n=nums.size();
        for(int i=n-1;i>=x;i--){
            s.insert(nums[i]);
            
        }
        
        int ans=1e9;
        int idx=x;
        auto it=s.upper_bound(4);
        
        for(int i=0;i<n;i++){
            if(i+x>=n){
                return ans;
            }
            auto it=s.upper_bound(nums[i]);
            if(it!=s.end()){
                ans=min(ans,abs(*it-nums[i]));
            }
            
            
            if(it!=s.begin()){
                it--;
                ans=min(ans,abs(*it-nums[i]));
            }
           
            s.erase(s.find(nums[idx]));
            idx++;
        }
        return ans;
    }
};