class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, make it odd.
        if (!(low & 1)) {
            low++;
        }

        // low could become greater than high due to incrementation
        // if it is, the answer is 0; otherwise, use the formula.
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};

// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/