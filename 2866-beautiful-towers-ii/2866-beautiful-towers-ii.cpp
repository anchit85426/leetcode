class Solution {
    void calc(vector<long long >&prefix,vector<int>&v){
        int n=v.size();
        stack<pair<long long,int>>s;
        for(int i=0;i<n;i++){
            if(i==0){
                prefix[i]=v[i];
                s.push({v[i],i});
            }
            else{
                while(!s.empty() and s.top().first>v[i]){
                    s.pop();
                }
                if(s.empty()){
                    // all the element would be a[i];
                    prefix[i]=1LL*(i+1)*v[i];
                    
                }
                else{
                    prefix[i]=prefix[s.top().second];
                    long long int  no_of_elements=i-s.top().second;
                    no_of_elements*=v[i];
                    prefix[i]+=no_of_elements;
                }
            }
            s.push({v[i],i});
        }
    }
public:
    long long maximumSumOfHeights(vector<int>& v) {
        int n=v.size();
        vector<long long >prefix(n,0),suffix(n,0);
        calc(prefix,v);
        reverse(v.begin(),v.end());
        calc(suffix,v);
        reverse(v.begin(),v.end());
        reverse(suffix.begin(),suffix.end());
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int value=prefix[i]+suffix[i]-v[i];
            ans=max(ans,value);
        }
        return ans;
    }
};