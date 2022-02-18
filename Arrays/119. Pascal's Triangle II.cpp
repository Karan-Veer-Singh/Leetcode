class Solution {
public:
    vector<int> getRow(int i) 
    {
        vector<int> ans;

        long long val = 1;

        for (int j = 0; j <= i; j++)
        {
            ans.push_back(val);
            val = val * (i - j) / (j + 1);
        }

        return ans;    
    }
};

// https://leetcode.com/problems/pascals-triangle-ii/submissions/
