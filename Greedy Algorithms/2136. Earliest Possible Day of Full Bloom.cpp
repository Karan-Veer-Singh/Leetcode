class Solution {
private:
    bool static compare(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
            v.push_back({plantTime[i], growTime[i]});

        sort(v.begin(), v.end(), compare);

        int time = 0, maxDays = 0;

        for (int i = 0; i < n; i++) {
            time += v[i].first;
            maxDays = max(maxDays, time + v[i].second);
        }

        return maxDays;
    }
};

// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/