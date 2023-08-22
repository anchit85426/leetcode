class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        for(int i=min(n,m);i>0;i--){
            int len=i;
            if(n%len!=0 or m%len!=0){
                continue;
            }
            else{
                int f1=n/len;
                
                int f2=m/len;
                string a=str1.substr(0,len);
                string b="";
                string c="";
                for(int i=0;i<f1;i++){
                    b+=a;
                }
                for(int i=0;i<f2;i++){
                    c+=a;
                }
                if(b==str1 and c==str2){
                    return str1.substr(0,len);
                }
                    
            }
        }
        return "";
    }
};