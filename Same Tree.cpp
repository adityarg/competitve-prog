/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Iterative Solution
class Solution {
public:
    // check if both are NULL or non-NULL
    bool both_diff(TreeNode* p, TreeNode* q)
        {return (p && !q) || (!p && q);}
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> g1,g2;
        auto curr1=p, curr2=q;
        
        while((curr1 || !g1.empty()) || (curr2 || !g2.empty()))
        {
            if(both_diff(curr1,curr2)) return false;
            
            while(curr1!=NULL && curr2!=NULL)
                {g1.push(curr1); curr1=curr1->left;
                 g2.push(curr2); curr2=curr2->left;}
            
            if(curr1!=NULL || curr2!=NULL) return false;
            
            curr1=g1.top(); g1.pop();
            curr2=g2.top(); g2.pop();
            if(curr1->val!=curr2->val) return false;
            
            curr1=curr1->right; curr2=curr2->right;
        }
        return true;
    }
};

// Recursive Solution
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q)
//     {
//         if(p==NULL && q==NULL) return true;
//         if(p==NULL || q==NULL) return false;
        
//         bool a = isSameTree(p->left,q->left);
//         if(p->val!=q->val) return false;
//         a = isSameTree(p->right,q->right) && a;
//         return a;
//     }
// };