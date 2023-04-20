class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int e3 = INT_MIN;
        stack<int>s;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]<e3)
                return true;
            while(!s.empty() && nums[i]>s.top()){
                e3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
