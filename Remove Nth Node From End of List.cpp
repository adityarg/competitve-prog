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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *former=head, *latter=head;
        while(n--) {latter=latter->next;}
        
        if(latter==NULL) return head->next; // for case when n=size of LL
        
        while(latter->next!=NULL) {former=former->next; latter=latter->next;}
        former->next = former->next->next;
        return head;
    }
};