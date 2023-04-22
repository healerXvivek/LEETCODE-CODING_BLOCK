class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       vector<int>hash(26,0);
        int ans=0;
        for(int i=0;i<chars.length();i++){
            hash[chars[i]-97]++;
        }
        
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            bool canMake=true;
            vector<int>org(hash);
            for(int j=0;j<temp.length();j++){
                if(hash[temp[j]-97]<=0){
                    canMake=false;
                    break;
                }else{
                    hash[temp[j]-97]--;
                }
            }
            hash=org;
            if(canMake){
                ans+=temp.length();
            }
        }
        return ans;
    }
};
