class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; i++) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};


//method 2 using one stack


class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        string res="";
        string num="";
        for(char c : s) {
            if(isdigit(c)) {
                num.push_back(c) ;                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                chars.push(res);
                chars.push(num);
                res = "";
                num = "";
            }
            else if(c == ']') {
                string tmp = res;
                int n=stoi(chars.top());
                for(int i = 1; i < n; i++) {
                    res += tmp;
                }
                chars.pop();
                res = chars.top() + res;
                chars.pop();
            }
        }
        return res;
    }
};
