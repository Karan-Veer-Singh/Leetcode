class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target)
    {
        int first = -1, second = -1;
        int start = 0, end = A.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (A[mid] == target) { first = mid; end = mid - 1; }
            else if (target < A[mid])   end = mid - 1;
            else    start = mid + 1;
        }

        start = 0, end = A.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (A[mid] == target) { second = mid; start = mid + 1;}
            else if (target < A[mid])    end = mid - 1;
            else start = mid + 1;
        }

        return {first, second};
    }
};

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/