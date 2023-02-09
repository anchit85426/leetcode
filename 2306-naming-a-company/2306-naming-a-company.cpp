class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        set<string>s[26];
        for(auto it:ideas){
            s[it[0]-'a'].insert(it.substr(1));
        }
        long long int ans=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long long int c1=0;
                long long int c2=0;
                for(auto it :s[i]){
                    if(s[j].count(it)==0){
                        c1++;
                    }
                }
                for(auto it :s[j]){
                    if(s[i].count(it)==0){
                        c2++;
                    }
                }
                ans+=c1*c2;
            }
        }
        return ans*2;
    }
};