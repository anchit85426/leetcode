class Solution {
    int ans=1e9;
    void solve(int idx,vector<int>&v,vector<int>&temp,int k){
        if(idx==v.size()){
          
            int element=*max_element(temp.begin(),temp.end());
            ans=min(ans,element);
            return;
        }
        int n=v.size();
        for(int i=0;i<k;i++){
            temp[i]+=v[idx];
            
            solve(idx+1,v,temp,k);
            temp[i]-=v[idx];
        }
        
    }
public:
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int>temp(k,0);
        solve(0,cookies,temp,k);
        return ans;
    }
};