class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        int cnt=0;
        vector<int>diff;
        set<char>x;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
               diff.push_back(i);
            }
            if(x.find(s[i])!=x.end()){
                flag=true;
            }
            x.insert(s[i]);
        }
        
        if(diff.size()==2){
            return s[diff[0]]==goal[diff[1]] and s[diff[1]]==goal[diff[0]];
        }
        if(diff.size()==1) return false;
        if(diff.size()==0 and flag==true) return true;
        return false;
    }
};