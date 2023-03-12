/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare
{
public:
    bool operator()(ListNode *A, ListNode *B)
    {
        return A->val > B->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& A)
    {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        for (int i = 0; i < A.size(); i++)
            if (A[i] != NULL)
                pq.push(A[i]);

        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = temp;

            if (temp->next != NULL)
                pq.push(temp->next);
        }

        return dummy->next;
    }
};

// https://leetcode.com/problems/merge-k-sorted-lists/