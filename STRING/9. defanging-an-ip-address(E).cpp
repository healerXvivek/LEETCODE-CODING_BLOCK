class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string defangIPaddr(string add) {
        string ans="";
        for(auto ch : add){
            if(ch=='.')
            ans+="[.]";
            else
            ans+=ch;
        }
        return ans;
    }
};
