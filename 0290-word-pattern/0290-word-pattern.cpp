class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,int>patterni;
        map<string,int>wordi;
        int i=0,n=pattern.size();
        istringstream in(s);
        for(string word;in>>word;i++){
            if(i==n or wordi[word]!=patterni[pattern[i]]) return false;
            
            patterni[pattern[i]]=wordi[word]=i+1;
        }
        return i==n;
    }
};