class Solution {
    vector<string>output;
    void solve(int index,string&digits,string temp,vector<string>&pad){
        if(index==digits.size()) {
            output.push_back(temp); return;
        }
        int character=digits[index]-'0';
        for(auto it :pad[character]){
            temp.push_back(it);
            solve(index+1,digits,temp,pad);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
       vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       string temp;
        solve(0,digits,temp,pad);
        return output;
    }
};