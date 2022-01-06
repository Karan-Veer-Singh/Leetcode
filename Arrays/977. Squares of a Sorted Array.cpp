class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        int n = A.size();

        vector<int> ans(n);

        int i = 0;
        int j = n-1;
        int index = n-1;

        while(i <= j)
        {
            int val1 = A[i] * A[i];
            int val2 = A[j] * A[j];

            if(val1 > val2)
            {
                ans[index] = val1;
                i++;
            }
            else
            {
                ans[index] = val2;
                j--;
            }

            index--;
        }

        return ans;   
    }
};

// https://leetcode.com/problems/squares-of-a-sorted-array/submissions/
