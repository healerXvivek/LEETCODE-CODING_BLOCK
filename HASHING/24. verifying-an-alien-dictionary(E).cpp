class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++)
         mp[order[i]] = i;
        for(int i = 0; i < words.size() - 1; i++){
            bool wordOrder = false;
            for(int j = 0; j < words[i].size() && words[i+1].size(); ++j){
                if(mp[words[i][j]] == mp[words[i+1][j]]) continue;
                if( mp[words[i][j]] < mp[words[i+1][j]] ) {wordOrder = true; break;}
                if( mp[words[i][j]] > mp[words[i+1][j]] ) return false;
            }
            if((!wordOrder) && (words[i].size() > words[i+1].size())) return false;
        }
        return true;
    }
};
