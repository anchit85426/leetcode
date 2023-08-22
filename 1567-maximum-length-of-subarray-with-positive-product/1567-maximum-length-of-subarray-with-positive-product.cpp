class Solution {
public:
    
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int window=0;
        int firstneg=-1;
        int ans=0;
        int neg=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                firstneg=-1;
                window=i+1;
                neg=0;
            }
            else{
                if(nums[i]<0 ){
                    neg++;
                }
                if(neg==1 and firstneg==-1){
                    firstneg=i;
                }
                if((neg%2)==0){
                    ans=max(ans,abs(i-window+1));
                }
                else{
                    ans=max(ans,abs(i-(firstneg+1)+1));
                }
            }
        }
        return ans;
    }
};