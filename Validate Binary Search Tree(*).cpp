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
// Revise this method, preorder is similar, postorder is different; read that too
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        long v=LONG_MIN;
        auto curr=root;
        stack<TreeNode*> g;
        
        while(!g.empty() || curr!=NULL)
        {
            while(curr) {g.push(curr); curr=curr->left;}
            curr=g.top(); g.pop();
            if(curr->val<=v) return false;
            else v=curr->val;
            curr=curr->right;
        }
        
        return true;
    }
};


// Recursive Solution
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>& v)
//     {
//         if(root==NULL) return;
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
//     bool isValidBST(TreeNode* root)
//     {
//         vector<int> v;
//         inorder(root,v);
        
//         for(int i=1;i<v.size();i++)
//             if(v[i]<=v[i-1]) return false;
//         return true;
//     }
// };