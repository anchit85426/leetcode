int N1=1e5;
vector<int>siv;
vector<vector<int>> adj;
vector<int> vis;
class Solution {
vector<int> factoristion(int n){
	vector<int> fact;

	while(n>1){
		
		int x=siv[n];
		while(n%x==0){
			n/=x;
		}
		fact.push_back(x);
	}
	return fact;
	
}
    int cnt=0;
    void dfs(int node){
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it);
            }
        }
    }


public:
    bool canTraverseAllPairs(vector<int>& nums) {
        siv.resize(N1+1,1);
        for(long long int  i=2;i<=N1;i++){
		if(siv[i]==1){
			
			siv[i]=i;
			for(long long int  j=i*i;j<=N1;j+=i){
				if(siv[j]==1){
					siv[j]=i;
				}
			}
		}
	}
        
       vector<int>x(100000,-1);
        int n=nums.size();
        adj.clear();
        vis.clear();
       adj.resize(n);
        vis.resize(n);
        for(int i=0;i<n;i++){
             vector<int>v=factoristion(nums[i]);
            
          
            for(auto it:v){
                
                if(x[it]!=-1){
                    
                    adj[x[it]].push_back(i);
                    adj[i].push_back(x[it]);
                }
                x[it]=i;
            }
        }
        
        
        
        
        
        dfs(0);
        
       
        return cnt==n;
        
        
    }
};