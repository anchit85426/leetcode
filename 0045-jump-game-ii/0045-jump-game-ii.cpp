class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0;
        int current=0;
        int steps=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(i==current){
                current=farthest;
                steps++;
            }
        }
        return steps;
            
    }
};