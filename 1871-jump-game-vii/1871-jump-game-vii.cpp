class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n=s.size();
        queue<int>q;
        q.push(0);
        int curr_max=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==n-1){
                return true;
            }
            for(int i=max(curr_max,node+minJump);i<=min(n-1,maxJump+node);i++){
                if(s[i]=='0'){
                    q.push(i);
                    
                }
            }
            curr_max=min(n-1,maxJump+node)+1;
        }
        return false;
    }
};