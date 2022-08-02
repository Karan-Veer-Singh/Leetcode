// Priority Queue

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k)   pq.pop();
            }
        }
        return pq.top();
    }
};

----------------------------------------------------------------------------------

// Binary Search

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), ans = 0;
        int left = matrix[0][0], right = matrix[n - 1][n - 1];

        while (left <= right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < n; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (count >= k) { ans = mid; right = mid - 1;}
            else    left = mid + 1;
        }
        return ans;
    }
};