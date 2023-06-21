class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int >prefix(n+1,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        vector<int>ans;
        for(int i=0;i<n;i++){
            int left=i-k;
            int right=i+k;
            if(left>=0 and right<n){
                long long int sum=0;
                sum+=prefix[right];
                if(left>=1){
                    sum-=prefix[left-1];
                }
                ans.push_back(sum/(right-left+1));
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};