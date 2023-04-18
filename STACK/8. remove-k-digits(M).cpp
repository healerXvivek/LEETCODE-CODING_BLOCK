class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.size()<=k)
        return "0";
        if (k==0)
        return s;

        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<s.size();i++){
            while(k>0 && st.size()>0 && st.top()>s[i]){
                    st.pop();
                    k--;
            }
            st.push(s[i]);
        }
        while(k>0 && st.size()>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        while(ans[0]=='0'){
            if(ans.size()==1)
            return ans;
            else 
            ans.erase(ans.begin());
        }
  
        return ans;
    }
};
