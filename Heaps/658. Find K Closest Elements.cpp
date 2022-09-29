class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int, int>> maxH;

        for (int i = 0; i < arr.size(); i++)
        {
            maxH.push({abs(arr[i] - x), arr[i]});
            if (maxH.size() > k)   maxH.pop();
        }

        while (!maxH.empty())
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// https://leetcode.com/problems/find-k-closest-elements/