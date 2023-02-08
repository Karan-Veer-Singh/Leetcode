class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int maxReach = 0;
        int currEnd = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (n <= 1)  return 0;

            maxReach = max(maxReach, i + nums[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = maxReach;
            }
        }

        return jumps;
    }
};

// https://leetcode.com/problems/jump-game-ii/
