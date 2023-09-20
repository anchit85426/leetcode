class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        map<string,int>mpp;
        for(auto it:words){
            mpp[it]++;
        }
        int odd=0;
        for(auto &it:mpp){
            if(it.first[0]==it.first[1]){
                if(it.second%2==1){
                    odd++;
                    ans+=(it.second*2-2);
                }
                else{
                    ans+=(it.second*2);
                }
                
            }
            else{
                string x;
                x+=it.first[1];
                x+=it.first[0];
                if(mpp.count(x)){
                    ans+=min(mpp[it.first],mpp[x])*4;
                    mpp[x]=0;
                }
            }
        }
       
        if(odd){
            ans+=2;
        }
        return ans;
    }
};