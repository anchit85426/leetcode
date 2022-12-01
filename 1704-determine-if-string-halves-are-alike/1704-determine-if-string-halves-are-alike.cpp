class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        char arr[10]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int countvowel=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<10;j++){
                if(s[i]==arr[j]){
                    countvowel++;
                    break;
                }
            }
        }
        for(int i=n/2;i<n;i++){
            for(int j=0;j<10;j++){
                if(s[i]==arr[j]){
                    countvowel--;
                    break;
                }
            }
        }
        return (countvowel==0);
    }
};