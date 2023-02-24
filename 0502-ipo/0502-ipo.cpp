class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>>v;
        int n=p.size();
        for(int i=0;i<n;i++){
            v.push_back({c[i],p[i]});
        }
        int i=0;
        sort(v.begin(),v.end());
        priority_queue<int>MaximizeProfit;
        while(k--){
            while(i<n and v[i].first<=w){
                MaximizeProfit.push(v[i].second);
                i++;
            }
            if(MaximizeProfit.empty()){
                break;
            }
            w+=MaximizeProfit.top();
            MaximizeProfit.pop();
        }
        return w;
    }
};