class Solution {
    int solve(vector<int>&arr,int j){
        if(j>=arr.size()) {
          
            return 1;
        }
        int total=0;
        for(int i=j;i<arr.size();i++){
           swap(arr[i],arr[j]);
            if((arr[j]%(j+1))==0 or ((j+1)%arr[j])==0){
                total+=solve(arr,j+1);
            }
            swap(arr[i],arr[j]);
          
        }
        return total;
    }
public:
    int countArrangement(int n) {
       vector<int>arr(n);
        for(int i=0;i<n;i++) arr[i]=i+1;
        return solve(arr,0);
    }
};