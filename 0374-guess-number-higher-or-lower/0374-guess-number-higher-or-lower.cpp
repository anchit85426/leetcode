/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        while(1){
            int number=low+(high-low)/2;
            if(guess(number)==0){
                return number;
            }
            else if(guess(number)==-1){
                high=number-1;
            }
            else if(guess(number)==1){
                low=number+1;
            }
        }
       
    }
};