class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int firstUniqChar(string s) {
        int v[26]={0};
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(v[s[i]-'a']==1)
            return i;
        }
        return -1;
    }
};
