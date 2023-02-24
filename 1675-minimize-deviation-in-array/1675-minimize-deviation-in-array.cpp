class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>minimize;
        int mini=INT_MAX;
        for(auto it :nums){
            if(it%2==1){
                minimize.push(it*2);
                mini=min(mini,it*2);
            }
            else{
                minimize.push(it);
                mini=min(mini,it);
            }
        }
        int res=INT_MAX;
        while(minimize.top()%2==0){
            int x=minimize.top();
         
             res=min(res,x-mini);
            mini=min(mini,x/2);
            minimize.pop();
            x=x/2;
            minimize.push(x);
          
           
        }
        res=min(res,minimize.top()-mini);
        return res;
    }
};