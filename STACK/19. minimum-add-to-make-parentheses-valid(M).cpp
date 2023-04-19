class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(auto ch: s){
            if(ch=='(')
            st.push(ch);
            else if(st.size()>0 && st.top()=='(' && ch==')')
            st.pop();
            else 
            st.push(ch);
        }
        return (st.size());
    }
};
