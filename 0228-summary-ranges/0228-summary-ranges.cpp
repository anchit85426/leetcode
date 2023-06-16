class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int start=nums[i];
            while(i+1<n and nums[i]+1==nums[i+1]){
                i++;
            }
            string x="";
            if(start!=nums[i]){
                x+=to_string(start);
                x+="->";
                x+=to_string(nums[i]);
            }
            else{
                x+=to_string(start);
            }
            ans.push_back(x);
            
            
           
        }
    return ans;
    }
};