class Solution {
public:
    int search(vector<int>& arr, int x) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==x)
            return mid;
            else if(arr[mid]>x)
            e=mid-1;
            else
            s=mid+1;
        }
        return -1;
    }
};
