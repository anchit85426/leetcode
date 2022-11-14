class Solution {
    static bool comapator(vector<int>&i1,vector<int>&i2){
        return i1[1]<i2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // n meeting in one room 
        // max non overlapped 
        int ans=1;
        sort(intervals.begin(),intervals.end(),comapator);
        int limit=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(limit<=intervals[i][0]){
                
                limit=intervals[i][1];
                ans++;
            }
        }
        return intervals.size()-ans;                                  
    }
};