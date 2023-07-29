#define ll long long int
class Solution {
    
private:
    bool check(ll n,vector<int>&batteries,ll mid){
        ll totalTime=0;
        for(ll it:batteries){
            totalTime+=min(it,mid);
        }
        return totalTime>=n*mid;
    }
public:

    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll low=0;
        ll high=0;
        for(auto it :batteries){
            high+=it;
        }
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(n,batteries,mid)){
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