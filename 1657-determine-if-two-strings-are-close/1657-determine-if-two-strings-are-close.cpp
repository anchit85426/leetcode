class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        for(auto it :word1){
            w1[it-'a']++;
            w3[it-'a']=1;
        }
        for(auto it :word2){
            w2[it-'a']++;
            w4[it-'a']=1;
        }
        sort(w1.begin(),w1.end()); sort(w2.begin(),w2.end());
        return w1==w2 and w3==w4;
        
    }
};