class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer,Boolean>present=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            present.put(nums[i],true);
        }
        int ans=0;
         HashMap<Integer,Boolean>checked=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(checked.containsKey(nums[i])==false && present.containsKey(nums[i]-1)!=true){
                int curr=0;
                int start=nums[i];
                while(present.containsKey(start)!=false){
                    curr++;
                    start+=1;
                    checked.put(start,true);
                }
                ans=Math.max(ans,curr);
            }
        }
        return ans;
    }
    
    
}