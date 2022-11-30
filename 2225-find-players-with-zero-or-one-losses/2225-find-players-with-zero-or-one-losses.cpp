class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int,int>mpp;
        set<int>s;
        for(auto it :matches){
            mpp[it[1]]++;
            s.insert(it[0]);
            s.insert(it[1]);
        }
          for(auto it :s){
            if(mpp.count(it)==0){
                ans[0].push_back(it);
            }
          }
            for(auto it :mpp){
                if(it.second==1){
                    ans[1].push_back(it.first);
                }
            }
        
       
        return ans;
    }
};