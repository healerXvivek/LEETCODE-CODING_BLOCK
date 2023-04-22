class Solution {
public:
    int numJewelsInStones(string j, string s) {
        unordered_map<char,int> m;
        for(auto ch : j)
        m[ch]=0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]]++;
            }
        }
        if (m.size()==0)
        return 0;
        int ans=0;
        for(auto i : m)
        ans+=i.second;
        return ans;
    }
};
