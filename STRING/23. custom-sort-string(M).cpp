class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto ch : s){
            mp[ch]++;
        }
        string ans="";
        for(auto ch : order){
            if(mp.find(ch) != mp.end()){
                while(mp[ch]>0){
                    ans+=ch;
                    mp[ch]--;
                }
                mp.erase(ch);
            }
        }
        for(auto i : mp){
            while(i.second > 0){
                ans+=i.first;
                i.second--;
            }
        }
        return ans;
    }
};
