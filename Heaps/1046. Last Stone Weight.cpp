class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() >= 2) {
            int first = maxHeap.top();  maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();
            if (first - second > 0)    maxHeap.push(first - second);
        }

        if (maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};

// https://leetcode.com/problems/last-stone-weight/