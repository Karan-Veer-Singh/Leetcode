class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> idxs(startTime.size(), 0);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](int a, int b) {
            return startTime[a] < startTime[b];
        });
        unordered_map<int, int> bsearchcache;
        function<int(int)> bsearch = [&](int i) {
            if (bsearchcache.count(i)) {
                return bsearchcache[i];
            }
            int lo = 0, hi = idxs.size() - 1;
            int eval = endTime[idxs[i]];
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (startTime[idxs[mid]] >= eval) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            return bsearchcache[i] = hi;
        };
        unordered_map<int, int> cache;
        function<int(int)> dp = [&](int idx) {
            if (cache.count(idx)) {
                return cache[idx];
            }
            int ans;
            if (idx == idxs.size()) {
                ans = 0;
            } else if (endTime[idxs[idx]] <= startTime[idxs[bsearch(idx)]]  ) {
                ans = max(profit[idxs[idx]] + dp(bsearch(idx)), dp(idx + 1) );
            } else {
                ans = max(profit[idxs[idx]], dp(idx + 1) );
            }
            return cache[idx] = ans;
        };
        return dp(0);
    }
};

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/