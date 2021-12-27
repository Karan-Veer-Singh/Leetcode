class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector< vector<int> > ans;
        
        if(intervals.size() == 0)
            return ans;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp = intervals[0];
        
        for(auto v : intervals)
        {
            if(v[0] <= temp[1])
                temp[1] = max(v[1], temp[1]);
            else
            {
                ans.push_back(temp);
                temp = v;
            }
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};

// https://leetcode.com/problems/merge-intervals/
