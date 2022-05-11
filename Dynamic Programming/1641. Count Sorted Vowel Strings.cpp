class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> ans(5, 1);
        for (int i = 2; i <= n; i++)
            for (int i = 3; i >= 0; i--)
                ans[i] += ans[i + 1];

        int res = 0;
        for (int i : ans)    res += i;
        return res;
    }
};

// TC - O(N)
// SC - O(1)
------------------------------------------------------------------

// Number of combinations with repetitions = (n+k-1)!/(k!*(n-1)!)
class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

// TC - O(1)
// SC - O(1)

// https://leetcode.com/problems/count-sorted-vowel-strings/