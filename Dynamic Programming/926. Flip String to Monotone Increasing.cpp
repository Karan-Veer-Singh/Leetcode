class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countFlips = 0, countOnes = 0;

        for (char c : s)
            if (c == '0')
                countFlips = min(countOnes, countFlips + 1);
            else
                countOnes++;

        return countFlips;
    }
};

// https://leetcode.com/problems/flip-string-to-monotone-increasing/