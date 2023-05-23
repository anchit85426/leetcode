class Solution {
    void dfs(string start,string end,map<string,vector<string>>&g,bool &found,map<string,int>&vis,double &value,map<string,double>&mpp){
        vis[start]=1;
        for(auto it :g[start]){
            string x=start;
            x+="->";
            x+=it;
           
            if(vis[it]!=1){
                 value*=mpp[x];
                if(it==end){
                    found=true;
                    return ;
                }
            
            dfs(it,end,g,found,vis,value,mpp);
            if(found==true){
                return ;
            }
            else{
                value/=mpp[x];
            }
        }
        }
        
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,double>mpp;
        map<string,vector<string>>g;
        int i=0;
        for(auto it :equations){
            string a=it[0];
            a+="->";
            a+=it[1];
            double f=values[i];
            mpp[a]=f;
            a.clear();
            a+=it[1];
            a+="->";
            a+=it[0];
            mpp[a]=1/values[i];
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
            
            i++;
        }
        vector<double>ans;
        for(auto it :queries){
            string x=it[0];
            x+="->";
            x+=it[1];
            if(mpp.count(x)){
                ans.push_back(mpp[x]);
                continue;
            }
            else{
                if(g.find(it[0])==g.end() || g.find(it[1])==g.end()){
                    ans.push_back(-1);
                }
                else{
                    bool found=false;
                    double value=1;
                    map<string,int>vis;
                    if(it[0]==it[1]){
                        ans.push_back(1);
                        continue;
                    }
                    dfs(it[0],it[1],g,found,vis,value,mpp);
                    if(found==true){
                        ans.push_back(value);
                    }
                    else{
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};