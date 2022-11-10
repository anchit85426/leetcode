class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>v;
        for(auto it:s){
            if(!v.empty() and v.back().first==it ){
                v.back().second++;
            }
            else{
                v.push_back({it,1});
            }
            if(v.back().second==k){
                v.pop_back();
            }
        }
        string ans="";
        for(auto it :v){
            ans.append(it.second,it.first);   
        }
        return ans;
    }
};