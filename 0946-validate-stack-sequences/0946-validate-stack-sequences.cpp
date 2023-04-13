class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int j=0;
        for(auto it :pushed){
            s.push(it);
            while(!s.empty() and s.top()==popped[j] ){
                j++;
                s.pop();
            }
        }
    return s.empty();
    }
   
    
};