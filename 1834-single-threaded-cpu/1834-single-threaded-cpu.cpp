class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<long,long>,vector<pair<long,long>>,
        greater<>>pq;
        long  n=tasks.size();
        for(long  i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int>ans;
        long  i=0;
        long time=0;
        while(i<n or pq.size()){
            if(pq.empty()){
                time=max(time,(long)tasks[i][0]);
            }
            
            while(  i<n and time>=tasks[i][0]){
                
                pq.emplace(tasks[i][1],tasks[i][2]);
                i++;
            }
            auto [it,index] =pq.top();
            pq.pop();
            time+=it;
            ans.push_back(index);
            
        }
        
        return ans;
    }
};