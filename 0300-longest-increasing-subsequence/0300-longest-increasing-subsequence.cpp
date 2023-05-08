class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int>temp;
        temp.push_back(v[0]);
        int len=1;
        int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i]>temp.back()){
                temp.push_back(v[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin();
                temp[ind]=v[i];
            }
        }
    return len;
    }
    
};