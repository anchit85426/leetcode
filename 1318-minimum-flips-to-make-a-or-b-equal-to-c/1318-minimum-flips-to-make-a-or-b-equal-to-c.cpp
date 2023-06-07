class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<32;i++){
            if((c>>i)&1){
                if((b>>i)&1 or (a>>i)&1){
                    
                }
                else{
                    cnt++;
                }
            }
            else{
                if((b>>i)&1){
                    cnt++;
                }
                if((a>>i)&1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};