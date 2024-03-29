class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 2;

        while (s <= e) {
            int mid = (s + e) >> 1;

            if (nums[mid] == nums[mid ^ 1])
                s = mid + 1;
            else
                e = mid - 1;
        }

        return nums[s];
    }
};

// https://leetcode.com/problems/single-element-in-a-sorted-array/