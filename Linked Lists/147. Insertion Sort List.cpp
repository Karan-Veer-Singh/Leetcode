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
    
    void sortedInsert(ListNode* &sorted, ListNode *newNode)
    {
        if(sorted == NULL || newNode->val <= sorted->val)
        {
            newNode->next = sorted;
            sorted = newNode;
        }
        else
        {
            ListNode *curr = sorted;
            while(curr->next != NULL && curr->next->val < newNode->val)
            {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *sorted = NULL;
        ListNode *current = head;
        
        while(current != NULL)
        {
            ListNode *next = current->next;
            sortedInsert(sorted, current);
            current = next;
        }
        
        head = sorted;
        return head;
    }
};

// https://leetcode.com/problems/insertion-sort-list/submissions/
