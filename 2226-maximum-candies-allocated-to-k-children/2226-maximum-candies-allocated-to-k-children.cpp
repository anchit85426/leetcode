class Solution {
   
public:
    int maximumCandies(vector<int>& v, long long k) {
        sort(v.begin(),v.end(),greater<int>());
        int n=v.size();
        int low=1;
        int high=1e8;
        auto possible=[&](int mid){
            long long int  total=0;
            for(int i=0;i<n;i++){
                
                    total+=v[i]/mid;
                
            }
           
            return total>=k;
            
        };
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid)){
            
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};