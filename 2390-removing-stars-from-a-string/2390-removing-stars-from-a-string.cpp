class Solution {
public:
    string removeStars(string s) {
        stack<char>t;
        int n=s.size();
        for(auto it :s){
            if(it!='*'){
                t.push(it);
            }
            else{
                t.pop();
            }
        }
        string q="";
        while(!t.empty()){
            q+=t.top();
            t.pop();
        }
        reverse(q.begin(),q.end());
        return q;
    }
};