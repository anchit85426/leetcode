class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mpp;
        for(auto it :arr){
            mpp[it]++;
        }
        map<int,int>mpp2;
        for(auto it :mpp){
            mpp2[it.second]++;
            if(mpp2[it.second]>=2){
                return false;
            }
        }
        return true;
    }
};