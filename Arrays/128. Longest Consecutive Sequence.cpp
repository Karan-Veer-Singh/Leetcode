class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s;

        for (int n : nums)
            s.insert(n);

        int longestStreak = 0;

        for (int n : nums)
        {
            if (!s.count(n - 1))
            {
                int currNum = n;
                int currStreak = 1;

                while (s.count(currNum + 1))
                {
                    currStreak++;
                    currNum++;
                }

                longestStreak = max(longestStreak, currStreak);
            }
        }

        return longestStreak;
    }
};

// https://leetcode.com/problems/longest-consecutive-sequence/