class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) 
    {
        int left= INT_MAX;
        int right = INT_MIN;
        int n = A.size();

        for(int i = 1; i < n; i++)
            if(A[i] < A[i-1])
                left = min(left, A[i]);

        for(int i = n-2; i >= 0; i--)
            if(A[i] > A[i+1])
                right = max(right, A[i]);

        if(left == INT_MAX && right == INT_MIN)
            return 0;

        int start = 0, end = n-1;

        for(; start < n; start++)
            if(A[start] > left)
                break;

        for(; end >= 0; end--)
            if(A[end] < right)
                break;

        return end-start+1;   
    }
};

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/
