class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        string temp="";
        s1+=" ";
        for(auto ch : s1){
            if(ch != ' '){
                temp+=ch;
            }
            else{
                m[temp]++;
                temp="";
            }
        }
        temp="";
        s2+=" ";
        for(auto ch : s2){
            if(ch != ' '){
                temp+=ch;
            }
            else{
                m[temp]++;
                temp="";
            }
        }
        vector<string> ans;
        for(auto i : m){
            if(i.second == 1)
            ans.push_back(i.first);
        }
        return ans;
    }
};
