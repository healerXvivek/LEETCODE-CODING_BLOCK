class Solution {
public:
    string toGoatLatin(string sentence) {
        sentence+=' ';
        string ans="";
        string word="";
        string pad_a="";
        for(int i=0;i<sentence.length();i++){
            char ch=sentence[i];
            if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')){
                word+=ch;
            }
            else{
                pad_a+='a';
                if(word[0]=='a' || word[0]=='e' || word[0]=='i' || word[0]=='o' || word[0]=='u' || word[0]=='A' || 
                word[0]=='E' || word[0]=='I' || word[0]=='O' || word[0]=='U'){
                    word+="ma"+pad_a;
                }
                else{
                    char c=word[0];
                    word=word.substr(1);
                    word+=c;
                    word+="ma"+pad_a;
                }
                ans+=word+" ";
                word="";
            }
        }
        ans.pop_back();
        return ans; 
    }
};



// method 2:-

class Solution {
 public:
  string toGoatLatin(string s) {
    string ans;
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    istringstream iss(s);
    string word;
    int i = 1;
    while (iss >> word) {
      if (i > 1)
        ans += ' ';
      if (vowels.count(word[0]))
        ans += word;
      else
        ans += word.substr(1) + word[0];

      ans += "ma" + string(i++, 'a');
    }

    return ans;
  }
};
