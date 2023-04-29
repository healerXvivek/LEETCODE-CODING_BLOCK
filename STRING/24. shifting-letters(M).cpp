class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        long long ps[n];
        ps[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            ps[i]=ps[i+1]+shifts[i];
        }
        for(int i=0;i<s.length();i++){
            s[i]=(char)((int)(((s[i]-'a')+ps[i])%26)+'a');
        }
        return s;
    }
};


//metod 2:-

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        long long ps=0;
        for(int i=s.length()-1;i>=0;i--){
            ps+=shifts[i];
            s[i]=(char)((((s[i]-'a')+ps)%26)+'a');
        }
        return s;
    }
};
