class Solution {
public:
    bool match(char a,char b){
        return(a=='(' && b==')' ||a=='{' && b=='}' ||a=='[' && b==']');
    }
    bool isValid(string st) {
        stack<char> s;
        for (auto ch : st){
            if (ch=='(' || ch=='{' || ch=='[')
            s.push(ch);
            else{
                if(s.empty())
                return false;
                else if(match(s.top(),ch)==false)
                return false;
                else
                s.pop();
            }
        }
        return(s.empty());
    }
};
