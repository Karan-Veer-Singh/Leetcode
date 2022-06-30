class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, steps = 0;
        while (i < j) {
            steps += (nums[j] - nums[i]);
            i++; j--;
        }
        return steps;
    }
};

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/