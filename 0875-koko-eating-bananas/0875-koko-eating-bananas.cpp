class Solution {
    bool check(long long int  mid,vector<int>&v,int h){
       long long int  t=0;
        for(auto it :v){
            t+=((it+mid-1)/mid);
        }
        
        return t<=h;
    }
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int l=0;
        sort(v.begin(),v.end());
        int n=v.size();
        long long int high=1e9;
        while(l+1<high){
            long long int mid = l + ((high - l) / 2);
            if(check(mid,v,h)){
               
                high=mid;
                
            }
            else{
                l=mid;
            }
        }
        return high;
    }
};