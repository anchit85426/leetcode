class Solution {
public:
    vector<int> goodIndices(vector<int>& v, int k) {
        vector<int>ans;
        int n=v.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        for(int i=1;i<n;i++){
            if(v[i]<=v[i-1]){
                prefix[i]+=prefix[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(v[i]<=v[i+1]){
                suffix[i]+=suffix[i+1];
            }
        }
        for(auto it :suffix){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=k;i<n-k;i++){
            if(min(prefix[i-1],suffix[i+1])>=k){
                ans.push_back(i);
            }    
        }
        return ans;
    }
};