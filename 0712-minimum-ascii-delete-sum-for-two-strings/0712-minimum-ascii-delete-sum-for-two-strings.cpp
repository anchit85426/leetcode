class Solution {
    vector<vector<int>>dp;
    int solve(string &s1,string &s2,int i,int j){
         if(i==-1 and j==-1){
            return 0;
        }
        if(i<0 or j<0){
            int sum=0;
            int k=i;
            while(k>=0){
                sum+=int(s1[k]);
                k--;
            }
            k=j;
            while(k>=0){
                sum+=int(s2[k]);
                k--;
            }
            return sum;
        }
       
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i-1,j-1);
        else return dp[i][j]=min(int(s1[i])+solve(s1,s2,i-1,j),int(s2[j])+solve(s1,s2,i,j-1));
        
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int sum=0;
        dp[0][0]=0;
        for(int i=1;i<=m;i++) {
            sum+=s2[i-1];
            dp[0][i]=sum;
            
        }
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=s1[i-1];
          dp[i][0]=sum;  
        } 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    
                    dp[i][j]=min(dp[i-1][j]+int(s1[i-1]),dp[i][j-1]+int(s2[j-1]));
                }
            }
        }
        return dp[n][m];
        
    }    
    };