class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0  or (i>0 and nums[i]!=nums[i-1])){
                int low=i+1;
                int high=n-1;
                int sum=-nums[i];
                while(low<high){
                   if(nums[low]+nums[high]==sum){
                       vector<int>temp;
                       temp.push_back(nums[i]);
                       temp.push_back(nums[low]);
                       temp.push_back(nums[high]);
                       ans.push_back(temp);
                       while(low<high and nums[low]==nums[low+1]) low++;
                       while(high>low and nums[high]==nums[low-1])high--;
                       low++;
                       high--;
                   }
                    else if(nums[low]+nums[high]<sum){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};