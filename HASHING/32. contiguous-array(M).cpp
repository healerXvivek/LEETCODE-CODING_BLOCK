class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> s;
        int ps=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            ps+=nums[i] ? 1: -1;
            if(ps==0)
            res=i+1;
            else if(s.find(ps) != s.end()){
                res=max(res,i-s[ps]);
            }
            else
            s[ps]=i;
        }
        return res;
    }
};


// method 2 :-


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> vect(2 * n + 1, INT_MIN);
        vect[nums.size()] = -1;
        int totalSum = 0, maxLength = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += (nums[i] ? 1 : -1);
            if (vect[totalSum + n] >= -1)
                maxLength = max(maxLength, i - vect[totalSum + n]);
            else
                vect[totalSum + n] = i;
        }
        return maxLength;
    }
};
