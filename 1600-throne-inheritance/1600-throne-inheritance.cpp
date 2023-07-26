class ThroneInheritance {
public:
    map<string ,vector<string>>v;
    map<string ,bool>dead;
    string root;
    ThroneInheritance(string kingName) {
        root=kingName;
    }
    
    void birth(string parentName, string childName) {
        v[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name]=true;
    }
    void dfs(string root,vector<string>&ans)
    {
        if(dead[root]==false){
            ans.push_back(root);
        }
        for(auto it :v[root]){
            dfs(it,ans);
        }
    }
        vector<string> getInheritanceOrder() {
        vector<string>ans;
            dfs(root,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */