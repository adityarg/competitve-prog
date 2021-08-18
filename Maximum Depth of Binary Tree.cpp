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
    int maxDepth(TreeNode* root)
    {
        if(root==NULL) return 0;
        int ans=0;
        queue<tuple<TreeNode*,int> > g;
        g.push({root,1});
        
        while(!g.empty())
        {
            auto [curr,h]=g.front(); g.pop();
            ans=max(ans,h);
            
            if(curr->left)  g.push({curr->left,h+1});
            if(curr->right) g.push({curr->right,h+1});
        }
        return ans;
    }
};

// Recursive Solution
// class Solution {
// public:
//     void dfs(TreeNode* curr, int h,int& ans)
//     {
//         if(curr==NULL) return;
//         ans=max(ans,h);
        
//         dfs(curr->left,h+1,ans);
//         dfs(curr->right,h+1,ans);
//     }
//     int maxDepth(TreeNode* root)
//     {
//         int ans=0;
//         dfs(root,1,ans);
//         return ans;
//     }
// };