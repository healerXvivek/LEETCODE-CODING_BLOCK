// method 1 : - using stack

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        stack<string> st;
        while(iss >> word){
            st.push(word);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            ans+=' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};


// method 2 : - reversing individual words and then entire sentence

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        string ans="";
        while(iss >> word){
            int i=0;
            int j=word.length()-1;
            while(i<=j){
                swap(word[i],word[j]);
                i++;
                j--;
            }
            ans+=word+' ';
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
