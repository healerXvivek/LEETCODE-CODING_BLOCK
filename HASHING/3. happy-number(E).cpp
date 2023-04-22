class Solution {
public:
    int numSquareSum(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1 && !st.count(n)){
            st.insert(n);
            n = numSquareSum(n);
        }
        return (n == 1);
    }
};
