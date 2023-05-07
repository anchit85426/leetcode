class Solution {
    int res=0;
    int rec(int i,vector<int>&cost){
        if(i>=cost.size()){
            return 0;
        }
        int a=rec(2*i+1,cost);
        int b=rec(2*i+2,cost);
        res+=abs(a-b);
        return cost[i]+max(a,b);
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        rec(0,cost);
        return res;
    }
};