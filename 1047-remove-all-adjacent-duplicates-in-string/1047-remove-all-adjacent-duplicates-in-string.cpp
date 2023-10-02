class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty()==false){
                if(st.top()==s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string s1="";
        while(st.empty()==false){
            s1+=st.top();
            st.pop();
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};