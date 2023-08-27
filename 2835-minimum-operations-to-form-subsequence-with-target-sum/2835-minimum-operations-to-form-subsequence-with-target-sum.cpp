class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long>cnt(32,0);
        for(auto it:nums){
            int power=0;
            while(it%2==0){
                it/=2;
                power++;
            }
            cnt[power]++;
        }
        long long  int sum=0;
        int ans=0;
        for(int i=0;i<31;i++){
            if((target>>i)&1==1){
                if(cnt[i]>=1){
                    cnt[i]--;
                    sum+=cnt[i]*(1<<i);
                }
                else if(sum>=(1<<i)){
                    sum-=(1<<i);
                    
                }
                else{
                    bool found=false;
                    for(int j=i+1;j<32;j++){
                        if(cnt[j]>=1){
                            found=true;
                            for(int k=j;k>i;k--){
                                cnt[k]-=1;
                                cnt[k-1]+=2;
                                ans++;
                            }
                            break;
                        }
                    }
                    if(found==false){
                        return -1;
                    }
                    i--;
                   
                }
            }
            else{
                sum+=(cnt[i]*(1<<i));
            }
        }
        return ans;
    }
};