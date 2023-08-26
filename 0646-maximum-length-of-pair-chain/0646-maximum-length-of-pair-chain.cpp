class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        else return a[0]<b[0];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comp);
        int ans=0;
        int cnt=1;
        int n=pairs.size();
        int p=pairs[0][1];
        for(int i=1;i<n;i++){
            if(pairs[i][0]>p){
                p=pairs[i][1];
                cnt++;
            }
         
        }
        ans=max(ans,cnt);
        return cnt;
    }
};