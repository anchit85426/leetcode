class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& v, int k, int value) {
        int n=v.size();
        vector<int>ans;
        vector<int>x(101,0);
        for(int i=0;i<k;i++){
            x[v[i]+50]++;
        }
        int last=1e8;
        int num=0;
        for(int i=0;i<=50;i++){
            if(x[i]>=1 and i-50<0) {
                
                num+=x[i];
            }
        }
        
        int q=0;
        if(num>=value){
           for(int i=0;i<=50;i++){
               if(x[i]>=1 and i-50<0){
                   q+=x[i];
                   if(q>=value){
                       ans.push_back(i-50);
                       break;
                   }
                   
               }
           }
        }
        else{
            ans.push_back(0);
        }
      
        int f=0;
        for(int i=k;i<n;i++){
            if(f>=n) return ans ;
            x[v[f]+50]--;
            x[v[i]+50]++;
            num=0;
          
            for(int i=0;i<=50;i++){
                if(x[i]>=1 and i-50<0) {
                    num+=x[i];
                }
          }  
             q=0;
        if(num>=value){
           for(int i=0;i<=50;i++){
               if(x[i]>=1 and i-50<0){
                   q+=x[i];
                   if(q>=value){
                       ans.push_back(i-50);
                       break;
                   }
                   
               }
           }
        }
        else{
            ans.push_back(0);
        }
          f+=1;  
        }
        return ans;
    }
};