class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        vector<int> v;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                v.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return v;
    }
};


// method 2:-

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> freq;
        vector<int> ans;

        for(int i=0; i<nums1.size(); i++){
            freq[nums1[i]]++;
        }

        for(int i=0;i<nums2.size(); i++){
            if(freq[nums2[i]]-- >0) 
                ans.push_back(nums2[i]);
        }

        return ans;

    }
};
