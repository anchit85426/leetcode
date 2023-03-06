int mod=1e9+7;
class Solution {
public:
    int countWays(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        
        vector<int>temp=intervals[0];
        int n=intervals.size();
        for(auto it :intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        int m=ans.size();
        long long x=1;
       while(m--){
            x*=2;
            x%=mod;
        }
        return x;
    }
};