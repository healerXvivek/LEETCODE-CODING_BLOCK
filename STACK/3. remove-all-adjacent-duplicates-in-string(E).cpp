class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.size()>0 && st.top()==s[i])
            st.pop();
            else
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// method 2:-

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(int i = 0; i<s.length(); i++){
            if(ans.back() == s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
