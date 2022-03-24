class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boat = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit)  left++, right--;
            else    right--;
            boat++;
        }

        return boat;
    }
};

// TC - O(NlogN)
// SC - O(1)
-------------------------------------------------------------------------- -

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit + 1, 0);

        for (int p : people) count[p]++;

        int i = 0;
        for (int j = 1; j <= limit; j++)
            while (count[j]--)
                people[i++] = j;

        int left = 0;
        int right = people.size() - 1;
        int boat = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit)  left++, right--;
            else    right--;
            boat++;
        }

        return boat;
    }
};

// TC - O(N)
// SC - O(limit)


// https://leetcode.com/problems/boats-to-save-people/