class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(auto c : s){
            if(c == '('){
                if(st.size() > 0){
                    ans += c;
                }
                st.push(c);
            }
            else if(c == ')'){
                if(st.size() > 1){
                    ans += c;
                }
                st.pop();
            }
        }
        return ans;
    }
};


//method 2:-

class Solution {
public:
    string removeOuterParentheses(string s) {
        int st=0;
        string ans;
        for(auto a: s)
        {
            if(a == '(')
            {
                if(st>0)
                {
                    ans+='(';
                }
                st++;
            }
            else
            {
                if(st>1)
                {
                    ans+=')';
                }
                st--;
            }
        }
        return ans;
    }
};
