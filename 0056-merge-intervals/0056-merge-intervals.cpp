class Solution {
    bool static sortbysec(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        
        vector<int>temp=intervals[0];
        int n=intervals.size();
        for(auto it :intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};