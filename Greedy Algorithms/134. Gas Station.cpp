class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), lowest_index = 0;
        int totalGas = 0, totalCost = 0, currGas = 0;

        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas = currGas + gas[i] - cost[i];

            if (currGas < 0) {
                lowest_index = i + 1;
                currGas = 0;
            }
        }

        if (totalGas >= totalCost)
            return lowest_index;
        else
            return -1;
    }
};

// https://leetcode.com/problems/gas-station/