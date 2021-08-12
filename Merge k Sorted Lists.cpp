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
    bool operator() (ListNode* a, ListNode* b)
    {
        if(a->val >= b->val) return true;
        else return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue <ListNode*, vector<ListNode*>, Compare> g;
        ListNode* head = new ListNode(), *temp=head;
        int k=lists.size();
        
        for(int i=0;i<k;i++)
            if(lists[i]!=NULL) g.push(lists[i]);
        while(g.size()>0)
        {
            temp->next=g.top(); temp=temp->next;
            auto t = g.top()->next;
            g.pop();
            if(t!=NULL) g.push(t);
        }
        
        return head->next;
    }
};