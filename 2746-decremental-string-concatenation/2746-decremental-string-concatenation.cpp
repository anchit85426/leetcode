class Solution {
    public:
  int dp[1001][27][27];
    int solve(vector<string>&words,int idx,char firstChar,char lastChar){
        if(idx==words.size()) return 0;
        if(dp[idx][firstChar-'a'][lastChar-'a']!=-1) return dp[idx][firstChar-'a'][lastChar-'a'];
        int res=80000;
        string word=words[idx];
        int len=word.size();
        if(word.back()==firstChar){
            res=min(res,len-1+solve(words,idx+1,word[0],lastChar));
        }
        else res=min(res,len+solve(words,idx+1,word[0],lastChar));    
        if(lastChar==word[0]) res=min(res,len-1+solve(words,idx+1,firstChar,word.back()));
        else res=min(res,len+solve(words,idx+1,firstChar,word.back()));
        return dp[idx][firstChar-'a'][lastChar-'a']=res;
    }

    int minimizeConcatenatedLength(vector<string>& words) {
       memset(dp,-1,sizeof(dp));
        return words[0].size()+solve(words,1,words[0][0],words[0].back());
        
    }
};