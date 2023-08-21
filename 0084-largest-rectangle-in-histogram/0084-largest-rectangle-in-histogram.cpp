class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        vector<int>left(n);
        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=0;
            }
            else{
                left[i]=s.top()+1;
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n-1;
            }
            else{
                right[i]=s.top()-1;
            }
            
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]+1)*heights[i]);
        }
        return ans;
    }
};