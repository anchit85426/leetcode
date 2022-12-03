class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        vector<pair<int,char>>v;
        for(char it :s){mpp[it]++;}
        for(auto it :mpp){
            v.push_back({it.second,it.first});
        }
        string ans="";
        sort(v.begin(),v.end());
       
        for(auto it :v){
            ans.append(it.first,it.second);
        }
        reverse(ans.begin(),ans.end());
      
        return ans;
        
        
        
        
    }
};