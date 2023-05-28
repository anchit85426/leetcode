int N1=1e5;
vector<int>siv;
class DisjointSet {
    
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
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

public:
    bool canTraverseAllPairs(vector<int>& nums) {
            DisjointSet st(nums.size());
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
        
        for(int i=0;i<n;i++){
             vector<int>v=factoristion(nums[i]);
            
          
            for(auto it:v){
                
                if(x[it]!=-1){
                    st.unionBySize(i,x[it]);
                    
                }
                else{
                
                x[it]=i;
                }
            }
        }
        
        
        
        
        
       for(auto it:st.size){
           if(it==n){
               return true;
           }
       }
        return false;
        
       
       
        
        
    }
};