class Solution {
public:
    int ans=0;
    void checkPalindrome(string s,int i,int j){
        while(i>=0 and j<s.length() and s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        
        if(s.length()==0) return 0;
        for(int i=0;i<s.length();i++){
            checkPalindrome(s,i,i);
            checkPalindrome(s,i,i+1);
        }
         return ans;
    }
   
};