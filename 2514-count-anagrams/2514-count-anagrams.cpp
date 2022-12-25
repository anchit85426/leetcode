#define mod 1000000007
#define ll long long int 
class Solution {
public:
    
    long long int  fact[100005];
    void factorial(){
        fact[0]=1;
        for(int i=1;i<100005;i++){
            fact[i]=i*fact[i-1]%mod;
        }
    }
    
    ll powmod(ll  a,ll b){
        ll ans=1;
        while(b>0){
            if(b&1) ans=ans*a %mod;
            a=a*a%mod;
            b>>=1;
        }
        return ans;
    }
    ll inv(ll n){
        return powmod(n,mod-2);
    }
    int countAnagrams(string s) {
        factorial();
        s.push_back(' ');
        map<char,ll>mpp;
        int cnt=0;
        ll ans=1;
        for(auto it :s){
            
            if(it==' '){
                ll value=fact[cnt];
                
                for(auto c :mpp){
                    ll divide1=fact[c.second];
                    
                    value=value*inv(divide1)%mod;
                    
                }
                ans=ans*value%mod;
                mpp.clear();
                cnt=0;
                    
            }
            else{
                mpp[it]++;
                cnt++;
            }
        }
        return ans;
    }
};