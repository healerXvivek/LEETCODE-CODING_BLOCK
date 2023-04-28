class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int n=arr.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))
            return mid;
            else if(arr[mid+1]>=arr[mid])
            s=mid+1;
            else
            e=mid-1;
        }
        return 0;
    }
};
