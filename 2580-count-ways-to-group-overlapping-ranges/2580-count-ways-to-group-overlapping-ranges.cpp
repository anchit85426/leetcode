int mod=1e9+7;
class Solution {
public:
    int countWays(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        
        vector<int>temp=intervals[0];
        int n=intervals.size();
        int ans=2;
        
        for(auto it :intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
               ans*=2;
                ans%=mod;
                temp=it;
            }
        }

        return ans;
    }
};