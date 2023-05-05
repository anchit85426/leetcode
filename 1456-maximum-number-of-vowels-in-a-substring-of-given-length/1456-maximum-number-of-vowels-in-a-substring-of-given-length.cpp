class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cnt++;
            }
        }
        ans=cnt;
        int j=0;
        for(int i=k;i<n;i++){
           if(s[j]=='a' or s[j]== 'e' or s[j]== 'i' or s[j]== 'o' or s[j]=='u'){
                cnt--;
            }
            if(s[i]=='a' or s[i]== 'e' or s[i]== 'i' or s[i]== 'o' or s[i]=='u'){
                cnt++;
            }
            ans=max(ans,cnt);
            j++;
        }
        return ans;
    }
};