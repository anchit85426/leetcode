class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ansi;
        int n=nums.size();
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                long long int sum=target-nums[j];
                sum-=nums[i];
                int front=j+1;
                int end=n-1;
                while(front<end){
                    if(nums[front]+nums[end]<sum) front++;
                    else if(nums[front]+nums[end]>sum) end--;
                    else{
                        vector<int>ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[front]);
                        ans.push_back(nums[end]);
                        ansi.push_back(ans);
                        while(front<end and nums[front]==nums[front+1]) front++;
                        while(front<end and nums[end]==nums[front-1]) end--;
                        front++;
                        end--;
                    }
                }
                while(j+1<n and nums[j]==nums[j+1]){
                        j++;
                }
            }
            while(i+1<n and nums[i]==nums[i+1]){
                i++;
            }
        }
        return ansi;
    }
};