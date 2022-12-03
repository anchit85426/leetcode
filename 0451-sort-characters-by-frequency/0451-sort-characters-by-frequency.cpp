class Solution {
public:
    string frequencySort(string s) {
        int count[256]={0};
        for(char it:s){
            count[it]++;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            return (count[a]>count[b] or count[a]==count[b] and a<b);
        });
        
        
        return s;
    }
};