class Solution {
public:
    int minMoves(vector<int>& v) {
        sort(v.begin(),v.end());
        int diff=0;
        int ans=0;
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]!=v[i+1]){
                diff+=abs(v[i+1]-v[i]);
            }
            ans+=diff;
        }
        return ans;
    }
};