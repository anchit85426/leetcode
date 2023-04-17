class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int element=*max_element(candies.begin(),candies.end());
        vector<bool>ans;
        for(auto it :candies){
            if(it+extraCandies>=element){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};