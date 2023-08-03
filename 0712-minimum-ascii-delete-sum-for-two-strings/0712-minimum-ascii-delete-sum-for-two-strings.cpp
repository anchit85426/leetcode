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
        dp.resize(n,vector<int>(m,-1));
        return solve(s1,s2,n-1,m-1);
    }    
    };