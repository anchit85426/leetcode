class Solution {
public:
    int maxProfit(vector<int>& v) {
        int mini=INT_MAX;
        int res=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            mini=min(mini,v[i]);
            res=max(res,v[i]-mini);
        }
        return res;
    }
};