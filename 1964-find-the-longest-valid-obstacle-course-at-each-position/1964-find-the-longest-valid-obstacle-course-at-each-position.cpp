class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>&v) {
        vector<int>temp;
        temp.push_back(v[0]);
        vector<int>ans;
        int len=1;
        int n=v.size();
        ans.push_back(1);
        for(int i=1;i<n;i++){
            if(v[i]>=temp.back()){
                temp.push_back(v[i]);
                len++;
                ans.push_back(len);
            }
            else{
                int ind=upper_bound(temp.begin(),temp.end(),v[i])-temp.begin();
                ans.push_back(ind+1);
                temp[ind]=v[i];
            }
        }
        return ans;
    }
};