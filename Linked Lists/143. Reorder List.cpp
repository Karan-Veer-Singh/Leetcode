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
ListNode* getMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverse(ListNode *curr)
{
    ListNode *prev = NULL;
    ListNode *nextNode;

    while(curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
    
void reorderList(ListNode* head) 
{
    if(head == NULL)
        return;

    ListNode *mid = getMiddle(head);

    ListNode *first = head;
    ListNode *second = reverse(mid);
    ListNode *temp;

    while(second->next != NULL)
    {
        temp = first->next;
        first->next = second;
        first = temp;

        temp = second->next;
        second->next = first;
        second = temp;    
    }       
}
    
};

// https://leetcode.com/problems/reorder-list/submissions/
