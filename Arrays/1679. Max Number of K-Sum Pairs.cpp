class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, count = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {i++; j--; count++;}
            else if (sum < k)    i++;
            else j--;
        }
        return count;
    }
};

// TC - O(NlogN)
// SC - O(1)

---------------------------------------------------------------------- -

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            int diff = k - nums[i];
            if (freq[diff] > 0) {count++; freq[diff]--;}
            else freq[nums[i]]++;
        }
        return count;
    }
};

// TC - O(N)
// SC - O(N)