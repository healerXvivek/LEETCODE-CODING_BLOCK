class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        vector<int> v;
        for(int i : s1){
            if(s2.find(i)!=s2.end())
            v.push_back(i);
        }
        return v;
    }
};


//method 2:-


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i=0;
        int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        set<int> s;
        for(int i=0; i<ans.size(); i++){
            s.insert(ans[i]);
        }
        vector<int> result;
        for(auto i:s){
            result.push_back(i);
        }
        return result;
    }
};
