class Solution {
private:
    void permuate(vector<int>nums,vector<int>&ds,int freq[],vector<vector<int>>&ans){
        if(nums.size()==ds.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                permuate(nums,ds,freq,ans);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        int freq[nums.size()];
        for(auto &it :freq){
            it=0;
        }
        vector<vector<int>>ans;
        vector<int>ds;
        permuate(nums,ds,freq,ans);
        return ans;
    }
};