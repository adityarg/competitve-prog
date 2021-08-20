/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Iterative Solution
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(head==NULL) return false;
        
        while(head)
        {
            if(head->next==head) return true;
            
            ListNode* n=head->next;
            head->next=head;
            head=n;
        }
        return false;
    }
};

// Recursive Solution
// class Solution {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         if(head==NULL) return false;
        
//         if(head->next==head) return true;
        
//         ListNode* n=head->next;
//         head->next=head;
        
//         return hasCycle(n);
//     }
// };