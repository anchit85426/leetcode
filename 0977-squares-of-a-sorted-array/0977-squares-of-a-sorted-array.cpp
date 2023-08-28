class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        
        int j=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int i=j-1;
        vector<int>ans;
        while(i>=0 and j<n){
            if((-nums[i])<nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
    }
};