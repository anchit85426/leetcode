class Solution {
    private:
    bool check(int mid,vector<int>&weight,int days){
        int i=0;
        int n=weight.size();
        int sum=0;
        int cnt=1;
        while( i<n){
            sum+=weight[i];
           
            if(sum>mid){
                cnt++;
                sum=weight[i];
            }
            i++; 
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxCapacity=0;
         for(int i = 0; i < n; i++)
            maxCapacity += weights[i];
        
        int l = *max_element(weights.begin(), weights.end()), h = maxCapacity;
        int ans=INT_MAX;
        while(l<=h){
            int mid=(h+l)/2;
            if(check(mid,weights,days)==true){
                ans=mid;
                h=mid-1;
                
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};