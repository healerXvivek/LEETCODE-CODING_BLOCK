class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(auto e : emails){
            string res="";
            for(auto ch : e){
                if(isalpha(ch))
                res+=ch;
                else if(ch=='+' || ch=='@')
                break;
            }
            res+=e.substr(e.find('@'));
            s.insert(res);
        }
        return (int)s.size();
    }
};
