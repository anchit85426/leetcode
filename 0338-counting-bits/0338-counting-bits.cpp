class Solution {
    int count(int n){
        int cnt=0;
        while(n){
            while(n%2==0){
                n/=2;
            }
            n/=2;
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};