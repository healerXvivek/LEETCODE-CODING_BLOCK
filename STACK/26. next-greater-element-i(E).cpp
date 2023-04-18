class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> m;
        for(int i=nums2.size()-1;i>=0;i--){
            if (s.size()==0){
                m[nums2[i]]=-1;
            }
            else if(s.size()>0 && s.top()>nums2[i]){
                m[nums2[i]]=s.top();
            }
            else if(s.size()>0 && s.top()<=nums2[i]){
                while(s.size()>0 && s.top()<=nums2[i]){
                    s.pop();
                }
                int k=s.empty() ? -1 : s.top();
                m[nums2[i]]=k;
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i : nums1)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};
