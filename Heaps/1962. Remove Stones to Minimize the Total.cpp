class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(), piles.end());
        int totalSum = accumulate(piles.begin(), piles.end(), 0);

        while (k--) {
            int curr = heap.top();
            heap.pop();
            int remove = curr / 2;
            totalSum -= remove;
            heap.push(curr - remove);
        }

        return totalSum;
    }
};

// https://leetcode.com/problems/remove-stones-to-minimize-the-total/