class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>v(n,0);
        int cnt=0;
        for(auto it :queries){
            
            int index=it[0];
            if(v[it[0]]!=0 and index-1>=0){
                if(v[it[0]]==v[index-1]){
                    cnt--;
                }
            }
             if(v[it[0]]!=0 and index+1<n){
                if(v[it[0]]==v[index+1]){
                    cnt--;
                }
            }
            v[it[0]]=it[1];
            if(v[it[0]]!=0 and index-1>=0){
                if(v[it[0]]==v[index-1]){
                    cnt++;
                }
            }
             if(v[it[0]]!=0 and index+1<n){
                if(v[it[0]]==v[index+1]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};