class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        vector<int>res;
        for(auto it :queries){
          res.push_back(upper_bound(prefix.begin(), prefix.end(), it) - prefix.begin());
        }
        return res;
    }
};