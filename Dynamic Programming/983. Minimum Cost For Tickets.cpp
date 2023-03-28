class Solution {
public:
    int getNextDaysIdx(vector<int>&days, int daysIdx, int ticketDuration)
    {
        int target = days[daysIdx] + ticketDuration - 1;
        for (int i = daysIdx + 1; i < days.size(); i++)
        {
            if (days[i] > target) return i;
        }
        return days.size();
    }
    int solve(vector<int>& days, vector<int>& costs, vector<int>& ticketDurations, vector<int>&dp, int daysIdx)
    {
        if (daysIdx == days.size()) return 0;

        if (dp[daysIdx] !=  -1) return dp[daysIdx];
        int minTravelCost = INT_MAX;
        //============================================================================
        for (int i = 0; i < 3; i++)
        {
            int ticketCost = costs[i], ticketDuration = ticketDurations[i];
            int nextDaysIdx = getNextDaysIdx(days, daysIdx, ticketDuration);

            int travelCost = ticketCost + solve(days, costs, ticketDurations, dp, nextDaysIdx);
            minTravelCost = min(minTravelCost, travelCost);
        }
        //==============================================================================
        return dp[daysIdx] = minTravelCost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int>ticketDurations = {1, 7, 30};
        vector<int>dp(days.size(), -1);
        int ans = solve(days, costs, ticketDurations, dp, 0);
        return ans;
    }
};

// https://leetcode.com/problems/minimum-cost-for-tickets/