class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1e9 + 7;
        long ans = 0;
        vector<long> count(101, 0);
        for (int x : arr)    count[x]++;

        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                int k = target - i - j;
                if (k < 0 || k > 100)    continue;
                else if (i == j && j == k)        ans += (count[i] * (count[i] - 1) * (count[i] - 2) / 6);
                else if (i == j && j != k)   ans += ((count[i] * (count[i] - 1) / 2) * count[k]);
                else if (i < j && j < k)     ans += (count[i] * count[j] * count[k]);
            }
        }
        return (int)(ans % MOD);
    }
};

// https://leetcode.com/problems/3sum-with-multiplicity/