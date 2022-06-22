class Solution {
public:
    int findKthLargest(vector<int>& A, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < A.size(); i++)
        {
            if (i < k)
            {
                pq.push(A[i]);
            }
            else if (A[i] > pq.top())
            {
                pq.pop();
                pq.push(A[i]);
            }
        }

        return pq.top();
    }
};

// https://leetcode.com/problems/kth-largest-element-in-an-array/
