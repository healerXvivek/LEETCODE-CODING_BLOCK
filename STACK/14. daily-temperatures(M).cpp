class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> v;
        stack<int> s;
        for(int i=t.size()-1;i>=0;i--){
            if(s.size()==0)
            v.push_back(0);
            else if (s.size()>0 && t[s.top()]>t[i])
            v.push_back(s.top()-i);
            else if (s.size()>0 && t[s.top()]<=t[i]){
                while(s.size()>0 && t[s.top()]<=t[i])
                s.pop();
                int k=s.empty() ? 0 : s.top()-i;
                v.push_back(k);
            }
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};


//optimised


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> v;
        stack<int> s;
        v.push_back(0);
        s.push(t.size()-1);
        for(int i=t.size()-2;i>=0;i--){
            while(s.size()>0 && t[s.top()]<=t[i])
            s.pop();
            int k=s.empty() ? 0 : s.top()-i;
            v.push_back(k);
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
