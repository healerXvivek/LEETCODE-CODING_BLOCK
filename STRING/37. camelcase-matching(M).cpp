class Solution {
    bool good(string s, string p) {
        int n = s.size(), m = p.size(), i = 0, j = 0;
        while(i < n) {
            if(s[i] == p[j]) j++;
            else if(isupper(s[i])) return false;
            i++;
        }
        return j == m ? true : false; 
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string s : queries) {
            ans.push_back(good(s, pattern));
        }
        return ans;
    }
};
