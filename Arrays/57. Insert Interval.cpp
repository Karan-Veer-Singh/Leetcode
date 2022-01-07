class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        
        for(auto curr : intervals)
        {
            if(curr[1] < newInterval[0])
            {
                ans.push_back(curr);
            }
            else if(newInterval[1] < curr[0])
            {
                ans.push_back(newInterval);
                newInterval = curr;
            }
            else
            {
                newInterval[0] = min(newInterval[0], curr[0]);
                newInterval[1] = max(newInterval[1], curr[1]);
            }           
        }
        
        ans.push_back(newInterval);
        return ans;
    }
};

// https://leetcode.com/problems/insert-interval/submissions/
