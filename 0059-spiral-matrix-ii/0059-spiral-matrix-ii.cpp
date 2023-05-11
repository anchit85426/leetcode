class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>g(n,vector<int>(n,0));
        int low=0;
        int high=n-1;
        int left=0;
        int right=n-1;
        int value=1;
        while(left<=right and low<=high){
            for(int i=left;i<=right;i++){
                g[low][i]=value;
                value++;
            }
            low++;
            for(int i=low;i<=right;i++){
                g[i][right]=value;
                value++;
            }
            right--;
            for(int i=right;i>=left;i--){
                g[high][i]=value;
                value++;
            }
            high--;
            for(int i=high;i>=low;i--){
                g[i][left]=value;
                value++;
            }
            left++;
        }
        return g;
    }
};