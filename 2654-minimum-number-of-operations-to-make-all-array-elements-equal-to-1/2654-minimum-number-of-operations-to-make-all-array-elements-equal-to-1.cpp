class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(auto it :nums) if(it==1) cnt++;
        if(cnt>=1) return n-cnt;
        int res=1e7;
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    res=min(res,n-1+j-i);
                    break;
                }
            }
        }
        if(res==1e7) return -1;
        return res;
    }
};