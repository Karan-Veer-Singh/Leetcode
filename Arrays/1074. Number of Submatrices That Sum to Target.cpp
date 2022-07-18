class Solution {
public:

    int numSubArraywTarget(vector<int>& make, int target)
    {
        int n = make.size();

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += make[j];

                if (sum == target)
                {
                    ans++;
                }
            }
        }

        return ans;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> make(m, 0);

            for (int row = i; row < n; row++)
            {
                for (int j = 0; j < m; j++)
                {
                    make[j] += matrix[row][j];
                }
                ans += numSubArraywTarget(make, target);
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/