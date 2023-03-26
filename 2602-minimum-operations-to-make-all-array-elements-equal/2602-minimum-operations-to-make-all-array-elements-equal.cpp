class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
       sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<long long int>prefix(n+1,0);
        prefix[1]=nums[0];
        for(int i=2;i<=n;i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }
        vector<long long >ans;
        for(auto it :queries){
           long long int index =upper_bound(nums.begin(),nums.end(),it)-nums.begin();
           
            long long int  secondpart=prefix[n]-prefix[index];
            
            long long int  value2=n-index;
            
            value2=value2*it;
            
         long long int   f=abs(secondpart-value2);
            long long int firstpart=0;
            
             if(index-1>=0){
                 firstpart+=prefix[index];
                 long long int  value1=(index)*it;
            
              f+=abs(firstpart-value1);
            }
            // cout<<f<<endl;
            ans.push_back(f);
       }
         return ans;
    }
   
};