class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f=[](string& w){
            return count(w.begin(),w.end(),*min_element(w.begin(),w.end()));
        };
        vector<int>count(13,0);
        for(auto it :words){
            count[f(it)]++;
        }
        for(int i=11;i>=0;i--){
            count[i]+=count[i+1];
        }
        
        vector<int>ans;
        for(auto it :queries){
            int x=f(it);
            ans.push_back(count[x+1]);
        }
        return ans;
    }
};