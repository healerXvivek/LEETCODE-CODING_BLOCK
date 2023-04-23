class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int n=guess.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[secret[i]]++;
        }
        int c=0;
        int nc=0;
        for(int i=0;i<n;i++){     
            if(secret[i]==guess[i])    // condition 1: same characters at same index
            c++;
        }
         
        for(int i=0;i<n;i++)   //to find total no. of common characters
        {
            if(m.find(guess[i])!=m.end())  
            {
                nc++;
                m[guess[i]]--;
                if(m[guess[i]]==0){    // if frequency of character=0, remove the character
                    m.erase(guess[i]);
                }
            }
        }
        nc=nc-c;      // no. of cows = total common characters - no. of bulls.          
        string ans;
        ans=to_string(c)+"A"+to_string(nc)+"B";
        return ans;
    }
};



//metod 2 :-

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string getHint(string secret, string guess) {
        
        int bulls = 0, cows = 0;
        int n = secret.length(), m = guess.length();
        if(n != m) return "";
        int s[10] = {0}, g[10] = {0};
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) bulls++;
            else{
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++) cows += min(s[i], g[i]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
