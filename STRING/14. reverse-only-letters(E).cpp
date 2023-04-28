class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string reverseOnlyLetters(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
                temp+=s[i];
            }
        }
        reverse(temp.begin(),temp.end());
        string ans="";
        int k=0;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
                ans+=temp[k];
                k++;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
