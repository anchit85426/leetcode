class Solution {
    unordered_map<string,int>mpp;
    string b;
    vector<vector<string>>ans;
private:
    void dfs(string word,vector<string>&seq){
        int sz=word.size();
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mpp[word];
        for(int i=0;i<sz;i++){
            char original_letter=word[i];
            for(char ch='a' ;ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() and mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=original_letter;
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)     {
        queue<string>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord});
        b=beginWord;
        st.erase(beginWord);
        int x=beginWord.size();
        mpp[beginWord]=1;
        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();
            if(word==endWord){
                break;
            }
            for(int i=0;i<x;i++){
                char original_letter=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=original_letter;
            }
            
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
        
    }
};