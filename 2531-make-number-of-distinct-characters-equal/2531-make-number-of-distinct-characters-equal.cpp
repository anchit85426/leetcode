class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<int,int>mpp1,mpp2;
        int dist1=0,dist2=0;
        for(auto it :word1){
            if(mpp1[it-'a']==0){
                dist1++;
            }
            mpp1[it-'a']++;
                
        }
     
        for(auto it :word2){
            if(mpp2[it-'a']==0){
                dist2++;
            }
            mpp2[it-'a']++;
        }
    
        cout<<dist1<<" "<<dist2<<endl;
        int original_dist1=dist1;
        int original_dist2=dist2;
        
        for(int i=0;i<26;i++){
         if(mpp1[i]!=0){
            for(int j=0;j<26;j++){
                if(mpp2[j]!=0 ){
                    if(i==j ){
                        if(dist1==dist2){
                            return true;
                        }
                        else{
                            continue;
                        }
                    }
                    
                    if(mpp2[i]==0){
                        dist2++;
                    }
                    if(mpp2[j]==1){
                        dist2--;
                    }
                    if(mpp1[j]==0){
                        dist1++;
                    }
                    if(mpp1[i]==1){
                        dist1--;
                    }
                    if(dist1==dist2){
                        
                        
                        return true;
                    }
                    dist1=original_dist1;
                    dist2=original_dist2;
                }      
            }
         }
        }
        return false;
    }
};