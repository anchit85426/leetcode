class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=0;
        long long int x=0;
        long long int  ans=0;
        for(auto it :arr){
            x+=it;
            if(x%2){
                ans+=1+even;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }
            
        }   
        int mod=1e9+7;
        ans=ans%mod;
        return ans;
    }
};