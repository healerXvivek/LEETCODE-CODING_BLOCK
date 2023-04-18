class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for(int i=0;i<a.size();i++){
            int flag=1;
            while (!s.empty() and flag)
            {
            if (s.top()>0 && a[i]<0){
                if (s.top()<abs(a[i]))
                s.pop();
                else if (s.top()==abs(a[i]))
                s.pop(),flag=0;
                else{
                flag=0;
                break;
                }
                
            }
            else
            break;
            }
            if(flag)
            s.push(a[i]);
        }
        vector<int> ans;
        while (!s.empty())
            ans.push_back(s.top()), s.pop();
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
};
