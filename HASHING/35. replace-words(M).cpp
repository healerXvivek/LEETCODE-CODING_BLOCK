class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        istringstream ss(s);
        unordered_map<string,int> m;
        for (auto i : d){
            m[i]++;
        }
        string w,ans="";
        while(ss>>w){
            bool flag = false;
            string temp = "";
            for(auto ch: w){
                temp+=ch;
                if(m.find(temp) != m.end()){
                    ans+=temp+" ";
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans+=w;
                ans+=" ";
            }
        }
        ans.pop_back();
        return ans ;
    }
};
