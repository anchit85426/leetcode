class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int  n=potions.size();
        for(auto it :spells){
            long long int  req=success/it;
            if(success%it!=0){
                req+=1;
            }
            int i=lower_bound(potions.begin(),potions.end(),req)-potions.begin();
           
            if(i==n){
                ans.push_back(0);
            }
            else{
                i++;
                ans.push_back(n-i+1);
            }
            
        }
        return ans;
    }
};