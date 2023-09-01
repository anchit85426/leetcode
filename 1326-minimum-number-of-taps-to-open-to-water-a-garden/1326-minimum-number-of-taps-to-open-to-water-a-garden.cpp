class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>v(n+1,0);
        for(int i=0;i<=n;i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            v[l]=max(v[l],r);
        }
        int ans=0;
        int curr_end=0;
        int max_end=0;
        
        for(int i=0;i<=n;i++){
            if(i>curr_end){
                return -1;
            }
            max_end=max(max_end,v[i]);
            if(curr_end==i){
                
                ans++;
                if(i==n){
                    return ans-1;
                }
                curr_end=max_end;
            }
        }
        return ans;
    }
};