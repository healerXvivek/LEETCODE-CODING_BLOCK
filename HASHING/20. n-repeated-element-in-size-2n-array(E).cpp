class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> e;
        for (int i = 0;i < nums.size();i ++){
            if (e.find(nums[i]) != e.end()) {
                return nums[i];
            }
            e.insert(nums[i]);
        }
        return -1;
    }
};



// method 2:-
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
            if(mp[i]==2)
            return i;
        }
        return 0;
    }
};
