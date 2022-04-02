class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, diff = INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int val = nums[i] + nums[low] + nums[high];
                if (val == target) return target;
                if (abs(target - val) < diff) {
                    diff = abs(target - val);
                    res = val;
                }
                if (val < target) low++;

                else    high--;
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/3sum-closest/