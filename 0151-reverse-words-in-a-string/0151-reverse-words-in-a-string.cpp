class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int str=0,end=0,i=0;
        int n=s.size();
        while(i<n){
            while(i<n and s[i]!=' '){
                s[end++]=s[i++];
            }
            if(str<end ){
                reverse(s.begin()+str,s.begin()+end);
                if(end==n) break;
                s[end++]=' ';
                str=end;
            }
            i++;
        }
        if(end>0 and s[end-1]==' ')s.resize(end-1);
        else s.resize(end);
        return s;
    }
};