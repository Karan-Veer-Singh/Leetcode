class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        bool flag = true;
        vector<vector<int>> freq(n + 1);
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i : nums)   mp[i]++;
        for (auto it : mp)   freq[it.second].push_back(it.first);

        for (int i = n; i > 0 && flag; i--) {
            for (int j : freq[i]) {
                if (k > 0)   {ans.push_back(j); k--;}
                else    {flag = false; break;}
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/top-k-frequent-elements/