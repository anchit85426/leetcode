class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        vector<int>v;
       
        for(auto it :nums){
            mpp[it]++;
        }
        // top k element
        priority_queue<pair<int,int>>q;
        for(auto it:mpp){
            q.push({it.second,it.first});
            if(mpp.size()-q.size()<k){
                v.push_back(q.top().second);
                q.pop();
                
            }
        }
        
        return v;
    }
};