class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int low = 1;
        int high = arr.size()-2;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid+1] > arr[mid])
                low = mid+1;
            else 
                high = mid-1;
        }
       return -1;
    }
};

// https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
