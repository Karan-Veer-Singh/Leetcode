class Solution {
private:
    bool dfs(vector<int> &matchsticks, int target, vector<int> &sides, int indx) {
        if (indx == matchsticks.size()) {
            return (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]);
        }

        for (int j = 0; j < 4; j++) {
            if (sides[j] + matchsticks[indx] > target)   continue;
            sides[j] += matchsticks[indx];
            if (dfs(matchsticks, target, sides, indx + 1) == true)  return true;
            sides[j] -= matchsticks[indx];
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4)  return false;

        int perimeter = 0;
        for (int stick : matchsticks)    perimeter += stick;

        if (perimeter % 4 != 0)    return false;
        int target = perimeter / 4;

        vector<int> sides(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, target, sides, 0);
    }
};

// https://leetcode.com/problems/matchsticks-to-square/