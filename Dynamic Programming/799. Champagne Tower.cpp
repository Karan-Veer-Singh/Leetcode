class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<double> top{(double)poured};
        
        for (int i = 0; i < query_row; i++)
        {
            vector<double> bottom(i + 2);
            
            for (int j = 0; j <= i; j++)
            {
                bottom[j] += max(top[j] - 1.0, 0.0) / 2.0;
                bottom[j + 1] += max(top[j] - 1.0, 0.0) / 2.0;
            }
            
            top = bottom;
        }
        
        return min(top[query_glass], 1.0);
    }
};

// https://leetcode.com/problems/champagne-tower/submissions/
