class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(auto it :nums){
            s.insert(it);
        }
        int longestStreak=0;
        for(auto it :nums){
            if(!s.count(it-1)){
                int currentnum=it;
                int currentStreak=1;
                while(s.count(currentnum+1)){
                    currentnum+=1;
                    currentStreak+=1;
                }
                longestStreak=max(currentStreak,longestStreak);
            }
            
        }
        return longestStreak;
    }
};