class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==0){
            return {{""}};
        }
        unordered_map<string,vector<string>> m;
        string temp="";
        for(auto s : strs){
            temp=s;
            sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
