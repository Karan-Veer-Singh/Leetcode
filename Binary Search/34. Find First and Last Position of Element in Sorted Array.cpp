class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) 
    {
        int first = -1;
        int second = -1;

        int start = 0;
        int end = A.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (A[mid] == target)
            {
                first = mid;
                end = mid - 1;
            }
            else if (target < A[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        start = 0;
        end = A.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (A[mid] == target)
            {
                second = mid;
                start = mid + 1;;
            }
            else if (target < A[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return {first, second};
    }
};

// 
