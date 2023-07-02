class Solution {
    int ans=0;
    void help(int idx, vector<vector<int>>&v,int l,vector<int>&temp){
        if(idx==v.size()){
          
            for(auto it:temp){
                
                if(it!=0){
                    return;
                }
            }
            ans=max(ans,l);
            return;
        }
        help(idx+1,v,l,temp);
        temp[v[idx][0]]--;
        temp[v[idx][1]]++;
        help(idx+1,v,l+1,temp);
        temp[v[idx][0]]++;
        temp[v[idx][1]]--;
         
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>temp(n,0);
        help(0,requests,0,temp);
        return ans;
    }
};