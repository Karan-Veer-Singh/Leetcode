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
class Solution {
public:
    
    void reverse(ListNode *curr, ListNode *end)
    {
        ListNode *prev = NULL;
        ListNode *nextNode;

        while (prev != end)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (head == NULL || head->next == NULL || k == 1)
        return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *beforeStart = dummy;
        ListNode *end = head;

        int i = 0;
        while (end != NULL)
        {
            i++;

            if (i % k == 0)
            {
                ListNode *start = beforeStart->next;
                ListNode *nextNode = end->next;
                reverse(start, end);
                beforeStart->next = end;
                start->next = nextNode;
                beforeStart = start;
                end = nextNode;
            }
            else
            {
                end = end->next;
            }
        }

        return dummy->next;   
    }
};

// https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
