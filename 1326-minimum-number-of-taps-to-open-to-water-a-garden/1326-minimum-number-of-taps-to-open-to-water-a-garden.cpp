class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans=0;
        int min=0;
        int max=0;
        int index=0;
        while(max<n){
            for(int i=index;i<=n;i++){
                if(i-ranges[i]<=min and i+ranges[i]>max){
                    max=i+ranges[i];
                    index=i;
                }
                
            }
            if(max==min){
                    return -1;
                }
            ans++;
            min=max;
        }
        return ans;
    }
};