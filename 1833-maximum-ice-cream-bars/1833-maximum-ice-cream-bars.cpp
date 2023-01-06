class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        for(auto it :costs){
            if(coins>=it){
                ans+=1;
                coins-=it;
                
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};