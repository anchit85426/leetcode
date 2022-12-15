class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
           vector<vector<int>>adj(vals.size()+1);
        for(auto it :edges){
            adj[it[1]].push_back(vals[it[0]]);
             adj[it[0]].push_back(vals[it[1]]);
        }
            int x=vals.size();
          for(int i=0;i<x;i++){
                    sort(adj[i].rbegin(), adj[i].rend());             
            }     
            
        
        long long int maxi=INT_MIN;
        if(edges.size()==0){
            sort(vals.begin(),vals.end(),greater<int>());
            return vals[0];
        }
        long long int  sum=0;
        if(k==0 ){
            sort(vals.begin(),vals.end(),greater<int>());
            return vals[0];
        }
        for(int i=0;i<x;i++){
                vector<int>m;
                int j=1;
                sum=vals[i];
                maxi=max(maxi,sum);
                for(auto it :adj[i]){
                    maxi=max(maxi,sum); 
                    sum+=it;
                    maxi=max(maxi,sum);
                    j++;
                    if(j==k+1){
                        break;
                    }
                }
               
               
            }
            
           
        
        return maxi;
    }
};