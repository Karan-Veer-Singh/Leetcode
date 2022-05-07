class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int leftMin = nums[0];
        for (int j = 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[k] > leftMin && nums[k] < nums[j])  return true;
            }
            leftMin = min(leftMin, nums[j]);
        }
        return false;
    }
};

// TC - O(N^2)
// SC - O(1)
------------------------------------------------------------------------------------

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int mini[n];
        mini[0] = nums[0];
        for (int i = 1; i < n; i++)
            mini[i] = min(mini[i - 1], nums[i]);

        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > mini[j]) {
                while (!s.empty() && s.top() <= mini[j])
                    s.pop();
                if (!s.empty() && s.top() < nums[j])
                    return true;
                s.push(nums[j]);
            }
        }
        return false;
    }
};

// TC - O(N)
// SC - O(N)


// https://leetcode.com/problems/132-pattern/