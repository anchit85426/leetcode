class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        long long int  ans=0;
        long long int  x=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            
            if(v[i]!=0)
            {
                ans+=x*(x+1)/2;
                x=0;
               
            }
            else{
                x++;
                }
                
               
            
            //cout<<i<<endl;
        }
    ans+=x*(x+1)/2;
    return ans;
    }
};