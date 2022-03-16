class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int i = 0, j = 0;

        for (int val : pushed)
        {
            pushed[i] = val;

            while (i >= 0 && pushed[i] == popped[j])
            {
                i--;
                j++;
            }

            i++;
        }

        return j == popped.size();

    }
};

// https://leetcode.com/problems/validate-stack-sequences/submissions/