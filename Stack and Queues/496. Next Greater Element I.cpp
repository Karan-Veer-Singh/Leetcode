class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        unordered_map<int, int> m;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() < nums2[i]) s.pop();
            int nge = s.empty() ? -1 : s.top();
            m[nums2[i]] = nge;
            s.push(nums2[i]);
        }

        for (int q : nums1)
            ans.push_back(m[q]);

        return ans;
    }
};

// https://leetcode.com/problems/next-greater-element-i/