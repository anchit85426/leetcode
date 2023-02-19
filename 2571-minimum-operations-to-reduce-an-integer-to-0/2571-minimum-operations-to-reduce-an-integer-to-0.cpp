class Solution {
public:
    int minOperations(int n) {
       if( __builtin_popcount(n)==1){
           return 1;
       }
        int x=log2(n);
        int y=pow(2,x);
        int first=1+minOperations(n-y);
        int y1=pow(2,x+1);
        int second=1+minOperations(y1-n);
        return min(first,second);
        
    }
};