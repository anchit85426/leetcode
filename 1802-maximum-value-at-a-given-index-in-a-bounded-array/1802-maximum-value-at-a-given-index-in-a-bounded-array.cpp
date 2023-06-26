class Solution {
    bool check(long long int  index,long long int value,int maxi,int n){
        long long int sum=0;
        
        if(value>index){
            long long int lastval=value-index;
            sum+=(value*(value+1))/2;
            sum-=(lastval*(lastval+1))/2;
        }
        else{
            sum+=(value*(value+1))/2;
            sum+=index-value;
        }
        index=n-index+1;
        if(value>index){
            long long int lastval=value-index;
            sum+=(value*(value+1))/2;
            sum-=(lastval*(lastval+1))/2;
        }
        else{
            sum+=(value*(value+1))/2;
            sum+=index-value;
        }
        sum-=value;
        return sum<=maxi;
    
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int low=1;
        index++;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(index,mid,maxSum,n)){
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