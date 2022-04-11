class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxA = 0, h, w;
        stack<int> s;

        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || heights[i] <= heights[s.top()])) {
                h = heights[s.top()];   s.pop();
                if (s.empty())  w = i;
                else    w = i - s.top() - 1;
                maxA = max(maxA, h * w);
            }
            s.push(i);
        }
        return maxA;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN, r = matrix.size(), c = matrix[0].size();
        vector<int> heights(c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1')  heights[j]++;
                else    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            ans = max(ans, area);
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximal-rectangle/submissions/