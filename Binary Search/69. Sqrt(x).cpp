class Solution {
public:
    int mySqrt(int n) 
    {
        int s = 1;
        int e = n;
        int ans = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (mid <= n / mid)
            {
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }

        return ans;    
    }
};

// https://leetcode.com/problems/sqrtx/submissions/
