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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *smallHead = new ListNode(0);
        ListNode *largeHead = new ListNode(0);

        smallHead->next = NULL;
        largeHead->next = NULL;

        ListNode *small = smallHead;
        ListNode *large = largeHead;

        while(head)
        {
            if(head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        small->next = largeHead->next;
        large->next = NULL;

        return smallHead->next;  
        
    }
};

// https://leetcode.com/problems/partition-list/submissions/
