class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int repeatedStringMatch(string a, string b) {
        int ans=1;
        string t=a;
        while(a.length() < b.length()){
                a+=t;
                ans++;
        }
        if(a.find(b)!=string::npos)
        return ans;
        a+=t;
        ans++;
        if(a.find(b)!=string::npos)
        return ans;
        return -1;
    }
};
