class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=n-1; i>=0 ; i--)
            s.push(nums[i]);
        for(int i=n-1; i>=0 ; i--){
            int ch=nums[i];
            while(!s.empty() && (s.top()<=ch))
            s.pop();
            if(s.empty())
                ans[i]=-1;
            else
            ans[i]=s.top();
            s.push(ch);
        }
        return ans;
    }
};
