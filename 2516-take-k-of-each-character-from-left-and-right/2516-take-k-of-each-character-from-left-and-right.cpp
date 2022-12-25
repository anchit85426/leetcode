class Solution {
    bool isSatisfied(vector<int>v,int k){
        if(v[0]>=k and v[1]>=k and v[2]>=k){
            return true;
        }
        return false;
    }
private:
    bool isValid(string s,int k,int cnt){
        vector<int>v(3,0);
        int n=s.length();
        for(int i=0;i<cnt;i++){
            v[s[i]-'a']++;
        }
        if (isSatisfied(v,k)){
            return true;
        }
        int left=cnt-1;
        int right=n-1;
        while(left>=0){
            v[s[left]-'a']--;
            v[s[right]-'a']++;
            if(isSatisfied(v,k)){
                return true;
            }
            left--;
            right--;
        }
        return false;
    }
    public:
    int takeCharacters(string s, int k) {
        int ans=INT_MAX;
        int n=s.length();
        int low=0;
        int high=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(isValid(s,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
    
};