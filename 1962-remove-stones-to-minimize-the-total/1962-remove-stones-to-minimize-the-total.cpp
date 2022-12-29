class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>q;
        for(auto it :piles){
            q.push(it);
        }
        while(k--){
            int x=q.top();
            x=(x+1)/2;
            q.pop();
            q.push(x);
        }
        int ans=0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};