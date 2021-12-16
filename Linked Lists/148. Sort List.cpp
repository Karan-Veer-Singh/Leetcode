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
    ListNode* getMid(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;

        if (l2->val < l1->val)
            swap(l1, l2);

        ListNode *res = l1;

        while (l1 != NULL && l2 != NULL)
        {
            ListNode *temp = NULL;
            while (l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *mid = getMid(head);
        ListNode *a = head;
        ListNode *b = mid->next;
        mid->next = NULL;

        a = sortList(a);
        b = sortList(b);

        ListNode *c = merge(a, b);
        return c;    
    }
};

// https://leetcode.com/problems/sort-list/submissions/
