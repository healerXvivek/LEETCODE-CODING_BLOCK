// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int firstBadVersion(int n) {
        int s=1;
        int e=n;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isBadVersion(mid)){
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return s;
    }
};
