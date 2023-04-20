class Solution {
public:
    // NSR = NEAREST SMALLER TO RIGHT
    // NSL = NEAREST SMALLER TO LEFT
    vector<int> NSR(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.size() == 0) v.push_back(n);
            else v.push_back(st.top());
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }

    vector<int> NSL(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.size() == 0) v.push_back(-1);
            else v.push_back(st.top());
            st.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> right = NSR(heights);
        vector<int> left = NSL(heights);
        int N = heights.size();
        int res = -1;
        for(int i = 0; i < N; i++){
            int area = (right[i] - left[i] - 1) * heights[i];
            res = max(res, area);
        }
        return res;
    }
};
