class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int start = 0;
        int end = A.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (A[mid] == target)
                return mid;
            if (target < A[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};

// https://leetcode.com/problems/search-insert-position/
