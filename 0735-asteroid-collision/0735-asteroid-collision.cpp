class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n=v.size();
        stack<int>s;
        
        for(int i=0;i<n;i++){
            if(v[i]>0 or s.empty()==true){
                s.push(v[i]);
            }
            else{
                while(s.empty()==false and  s.top()>0 and s.top()<abs(v[i])){
                    s.pop();
                }
                // when they are equal
                if(s.empty()==false and s.top()==abs(v[i])){
                    // both are removed
                    s.pop();
                }
                else{
                // if empty or a negative number present then push
                if(s.empty()==true or s.top()<0){
                    s.push(v[i]);
                }
                }
            }
        }
        vector<int>ans;
        while(s.empty()==false){
            ans.push_back(s.top());
            s.pop();
           
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};