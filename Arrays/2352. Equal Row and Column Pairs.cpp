class Trie {
public:
    int endCount = 0;
    map<int, Trie*> mp;
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        Trie* orig_trie = new Trie();
        int n = grid.size();

        // Add rows of the matrix in the trie
        for (int i = 0; i < n; i++) {
            Trie* temp_trie = orig_trie;
            for (int j = 0; j < n; j++) {
                if (temp_trie->mp.find(grid[i][j]) == temp_trie->mp.end())
                    temp_trie->mp[grid[i][j]] = new Trie();

                temp_trie = temp_trie->mp[grid[i][j]];
            }

            temp_trie->endCount += 1;
        }

        int ans = 0;
        // Traverse all the columns of the matrix in the trie
        for (int j = 0; j < n; j++) {
            Trie* temp_trie = orig_trie;
            for (int i = 0; i < n; i++) {
                if (temp_trie->mp.find(grid[i][j]) == temp_trie->mp.end())
                    break;

                temp_trie = temp_trie->mp[grid[i][j]];
            }

            ans += temp_trie->endCount;
        }

        return ans;
    }
};

// https://leetcode.com/problems/equal-row-and-column-pairs/