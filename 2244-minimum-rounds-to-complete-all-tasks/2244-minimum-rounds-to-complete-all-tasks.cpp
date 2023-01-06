class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mpp;
        for(auto it :tasks){
            mpp[it]++;
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==1){
                return -1;
            }
            ans+=(it.second+2)/3;
            
        }
        return ans;
    }
    
};