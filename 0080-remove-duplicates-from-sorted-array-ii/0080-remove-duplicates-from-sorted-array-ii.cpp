class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        if(nums.size()<=2){
            return nums.size();
        }
        for(auto it :nums){
            if(i==0 or i==1 or it!=nums[i-2]){
                nums[i]=it;
                i++;
            }
        }
        return i;
    }
};