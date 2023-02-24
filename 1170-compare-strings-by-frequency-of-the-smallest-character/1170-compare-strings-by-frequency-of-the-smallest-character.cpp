class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f=[](string& w){
            return count(w.begin(),w.end(),*min_element(w.begin(),w.end()));
        };
        vector<int>count(13,0);
        vector<int>res;
        int n=words.size();
        for(auto it :words){
            count[f(it)]++;
            res.push_back(f(it));
        }
        sort(res.begin(),res.end());
        vector<int>ans;
        for(auto it :queries){
            int x=f(it);
            int x1=upper_bound(res.begin(),res.end(),x)-res.begin();
            if(x1==n){
                ans.push_back(0);
                continue;
            }
            ans.push_back(n-x1);
            
        }
        return ans;
    }
};