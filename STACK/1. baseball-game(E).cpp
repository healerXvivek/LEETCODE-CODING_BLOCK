class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(ops[i]=="C"){
                s.pop();
            }
            else if(ops[i]=="D"){
                s.push(2*s.top());
            }
            else if (ops[i]=="+"){
                int e1=s.top();
                s.pop();
                int e2=s.top();
                s.push(e1);
                s.push(e1+e2);
            }
            else{
                s.push(stoi(ops[i]));
            }
        }
        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};
