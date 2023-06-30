class Solution {
public:
    void merge(vector<int>& nums, int m, vector<int>& nums2, int n) {
        int k=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 and j>=0){
            if(nums[i]>=nums2[j]){
                nums[k]=nums[i];
                i--;
                k--;
            }
            else{
                nums[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(j>=0){
            nums[k]=nums2[j];
            j--;
            k--;
        }
        while(i>=0){
            nums[k]=nums[i];
            k--;
            i--;
        }
   
    }
};