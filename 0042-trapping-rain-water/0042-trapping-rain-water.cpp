class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left_max=0,right_max=0,l=0,r=n-1;
        int res=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(left_max<=height[l]){
                    left_max=height[l];
                }
                else{
                    res+=(left_max-height[l]);
                }
                l++;
            }
            else{
                if(right_max<=height[r]){
                    right_max=height[r];
                }
                else{
                    res+=right_max-height[r];
                }
                r--;
            }
        }
        return res;
    }
};