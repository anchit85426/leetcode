class Solution {
public:
    string predictPartyVictory(string s1) {
       queue<int>r,d;
        int i=0;
        for(auto it :s1){
            if(it=='R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
            i++;
        }
        int n=s1.size();
       
        
    
    while(!r.empty() and !d.empty()){
        int d1=r.front();
        int d2=d.front();
        r.pop();
        d.pop();
        (d1>d2)?d.push(d2+n):r.push(d1+n);
    }
        if(r.size()) return "Radiant";
        return "Dire";
    }
};