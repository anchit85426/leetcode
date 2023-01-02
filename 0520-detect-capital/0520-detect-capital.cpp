class Solution {
public:
    bool detectCapitalUse(string word) {
        char m=word[0];
        int x=0;
      (isupper(m))? x+=1:x=0;
      
        int y=0;
        for(int i=1;i<word.size();i++){
            if(!islower(word[i])){
                y+=1;
            }
        }
       
        if(x+y==0 or x+y==word.size() or (x==1 and y==0)){
            return true;
        }
        return false;
    }
};