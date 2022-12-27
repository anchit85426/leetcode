class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>v;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            int x=capacity[i]-rocks[i];
            if(x!=0){
                v.push_back(x);
            }
        }
        sort(v.begin(),v.end());
        int ans=capacity.size()-v.size();
        for(auto it :v){
            if(additionalRocks>=it){
                ans+=1;
                additionalRocks-=it;
            }
            else{
                break;
            }
        }
        return ans;
    }
};