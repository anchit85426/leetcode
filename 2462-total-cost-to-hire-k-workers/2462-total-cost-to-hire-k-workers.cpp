class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<candidates;i++){
            q.push({costs[i],i});
        }
        int n=costs.size();
        for(int i=n-1;i>=n-candidates;i--){
            q.push({costs[i],i});
        }
        if(2*candidates>=n){
            sort(costs.begin(),costs.end());
            long long cost=0;
            for(int i=0;i<k;i++){
                cost+=costs[i];
            }
            return cost;
        }
       
        long long cost=0;
        int left=candidates-1,right=n-candidates;
        for(int i=0;i<k;i++){
            if(n-i<=2*candidates){
                cout<<i<<endl;
                 while(i!=k){
                   
                     int x1=q.top().first;
                     q.pop();
                     cost+=x1;
                     i++;
                 }
                return cost;
            }
            int x1=q.top().first;
            int pos1=q.top().second;
            q.pop();
            cost+=x1;
             
            if(pos1<=left){
                left++;
                q.push({costs[left],left});
            }
                else{
                    right--;
                    q.push({costs[right],right});
                }
              }
            
        
        return cost;
    }
};