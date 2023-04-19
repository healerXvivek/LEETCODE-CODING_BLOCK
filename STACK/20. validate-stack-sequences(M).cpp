class Solution{
public:
    bool validateStackSequences(vector<int> &push, vector<int> &pop){
        stack<int> st;
        int i = 0;
        for (int x : push){
            st.push(x);
            while (st.size() && st.top() == pop[i]){
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};
