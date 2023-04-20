class Solution {
    vector<vector<int>>dp;
    vector<vector<int>>freq;
    private:
    int find(vector<string>&words,string &target,int i,int j){
        if(j==target.length()) return 1;
        if(i==words[0].size() or words[0].size()-i<target.size()-j ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long int count=0;
        int currposs=target[j]-'a';
        count +=find(words, target, i + 1, j);
        count%=1000000007;
        long long int x=find(words,target,i+1,j+1)%1000000007;
        count += freq[i][currposs] * x;
        count%=1000000007;
        return dp[i][j] = count % 1000000007;
    }
public:
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=target.size();
       // void resize (size_type n, value_type val = value_type());
        freq.resize(words[0].size(),vector<int>(27,0));
        dp.resize(words[0].size(),vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[0].size();j++){
                int value=words[i][j]-'a';
                freq[j][value]++;
            }
        }
        return find(words,target,0,0);
    }
};