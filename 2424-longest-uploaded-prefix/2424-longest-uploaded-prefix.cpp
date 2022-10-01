class LUPrefix {
public:
    int m;
    set<int>s;
    LUPrefix(int n) {
        m=n;
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
    }
    
    void upload(int video) {
        s.erase(video);
    }
    
    int longest() {
        if(s.size()==0) return m;
        else{
            return *s.begin()-1;
        }
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */