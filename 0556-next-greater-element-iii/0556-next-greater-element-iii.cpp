class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int sz=s.size();
        vector<int>x;
        for(int i=sz-1;i>=1;i--){
            if((s[i]-'0')>(s[i-1]-'0')){
                
                int index=i-1;
                for(int j=sz-1;j>index;j--){
                     
                    if((s[j]-'0')>(s[index]-'0')){
                       
                        swap(s[j],s[index]);
                        break;
                    }
                }
                reverse(s.begin()+index+1,s.end());
                long long int ans=stoll(s);
               long long limit=pow(2,31)-1;
                if(ans>limit){
                    return -1;
                }
                return ans;
            }
        }
        return -1;
    }
};