class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int n=s.size();
        int max_cost=0;
        int sum=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(i>0 and s[i]!=s[i-1]){
                res+=sum-max_cost;
                max_cost=0;
                sum=0;
                
            }
            sum+=neededTime[i];
            max_cost=max(max_cost,neededTime[i]);
        }
        res+=sum-max_cost;
        return res;
    }
};