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
    void reorderList(ListNode* head)
    {
        // find middle node
        ListNode *slow=head, *fast=head;
        while(slow && fast && fast->next && fast->next->next)
            {slow=slow->next; fast=fast->next->next;}
        
        // break the LL from the middle
        fast=slow->next; slow->next=NULL;
        
        // reversing the second half
        ListNode *prev=NULL, *curr=fast;
        while(curr)
        {
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr; curr=n;
        }
        
        // merging
        ListNode *h1=head, *h2=prev;
        while(h2)
        {
            ListNode* n1=h1->next;
            h1->next=h2;
            ListNode* n2=h2->next;
            h2->next=n1;
            h1=n1; h2=n2;
        }
    }
};