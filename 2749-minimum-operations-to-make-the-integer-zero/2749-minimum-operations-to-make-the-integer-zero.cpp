class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2>num1){
            return -1;
        }
        for(int i=0;i<=100;i++){
            long long  diff=num1-1LL*(num2)*i;
            
            int bits= __builtin_popcountll(diff);
            
            if(bits<=i and diff>=i){
                return i;
            }
        }
        return -1;
    }
};