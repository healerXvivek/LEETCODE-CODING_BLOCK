class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
        int s=0;
        int e=arr.size()-1;
        if(arr[e]<= x)  
        return arr[0];
        char res=arr[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid] == x)
            s=mid+1;
            else if(arr[mid]<x)
            s=mid+1;
            else
            res=arr[mid], e=mid-1;
        }
        return res;
    }
};
