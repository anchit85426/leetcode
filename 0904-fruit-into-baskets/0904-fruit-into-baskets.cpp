class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int i=0;
        int j=0;
        int n=fruits.size();
        int count=0;
        int ans=0;
        while(i<n and j<n){
            mpp[fruits[j]]++;
            count++;
            if(mpp.size()<=2){
                
            }
            else{
                while(mpp.size()==3){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]]==0){
                        
                        mpp.erase(fruits[i]);
                        
                    }
                    count--;
                    i++;
                    
                }
            }
            j++;
            ans=max(ans,count);
        }
        return ans;
    }
};