class Solution {
    string solve(string a,string b,string c){
         string s="";
        s+=a;
       
         int sz=s.size();
        int j=0;
        // i==n or j==n to hoga 
        
        bool flag=0;
        for(int i=0;i<sz;i++){
            j=0;
            int k=i;
            if(s[k]==b[j]){
                while(k<sz and j<b.size() and s[k]==b[j]){
                    k++;
                    j++;
                }
                if(j==b.size()){
                    flag=1;
                    break;
                }
                else if(k==sz){
                    flag=1;
                    for(int i=j;i<b.size();i++){
                        
                        s+=b[i];
                        
                    }
                    break;
                    
                }
            }
        }
        if(flag==0){
            s+=b;
        }
        
        
           sz=s.size();
     j=0;
        // i==n or j==n to hoga 
        
         flag=0;
        for(int i=0;i<sz;i++){
            j=0;
            int k=i;
            if(s[k]==c[j]){
                while(k<sz and j<c.size() and s[k]==c[j]){
                    k++;
                    j++;
                }
                if(j==c.size()){
                    flag=1;
                    break;
                }
                else if(k==sz){
                    flag=1;
                    for(int i=j;i<c.size();i++){
                        
                        s+=c[i];
                        
                    }
                    break;
                    
                }
            }
        }
        if(flag==0){
            s+=c;
        }
        
        return s;
        
    }
public:
    string minimumString(string a, string b, string c) {
         // ab 
        string ans=solve(a,b,c);
        
        string x=solve(a,c,b);
        if(ans.size()>x.size()){
            ans=x;
        }
        else if(ans.size()==x.size()){
            ans=min(ans,x);
        }
        x=solve(b,a,c);
        // ans=min(ans,x);
         if(ans.size()>x.size()){
            ans=x;
        }
        else if(ans.size()==x.size()){
            ans=min(ans,x);
        }
         x=solve(b,c,a);
         if(ans.size()>x.size()){
            ans=x;
        }
        else if(ans.size()==x.size()){
            ans=min(ans,x);
        }
        // ans=min(ans,x);
         x=solve(c,a,b);
         if(ans.size()>x.size()){
            ans=x;
        }
        else if(ans.size()==x.size()){
            ans=min(ans,x);
        }
        // ans=min(ans,x);
         x=solve(c,b,a);
         if(ans.size()>x.size()){
            ans=x;
        }
        else if(ans.size()==x.size()){
            ans=min(ans,x);
        }
        // ans=min(ans,x);
       
       return ans;
        
    }
};