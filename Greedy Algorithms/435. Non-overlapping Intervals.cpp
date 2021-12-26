class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int size = intervals.size();
        int rem = 0;
        
        sort(intervals.begin(), intervals.end());
        
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int newEnd = intervals[i][1];
            
            if(start < end)
            {
                rem++;
                end = min(end, newEnd);
            }
            else
                end = newEnd;
        }
        
        return rem;
    }
};

// https://leetcode.com/problems/non-overlapping-intervals/submissions/
