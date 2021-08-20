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
class Solution {
public:
    pair<int,int> func(TreeNode* root)
    {
        if(root==NULL) return {INT_MIN,0};
        auto [s1,c1] = func(root->left);
        auto [s2,c2] = func(root->right);
        int r=root->val;
        
        // s = max{s1,s2,c1+c2+r,c1+r,c2+r,r}
        int s=max(s1,max(s2,max(c1+c2+r,max(c1+r,max(c2+r,r)))));
        // c = max{c1+r,c2+r,r}
        int c=max(c1+r,max(c2+r,r));
        
        return {s,c};
    }
    int maxPathSum(TreeNode* root)
    {
        auto [s,c]=func(root);
        return s;
    }
};