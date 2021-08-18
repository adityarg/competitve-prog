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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int> > g;
        TreeNode* curr=root; int h=0;
        
        g.push({curr,0});
        while(!g.empty())
        {
            auto [curr,h]=g.front();
            g.pop();
            
            if(h==ans.size()) {vector<int> v; ans.push_back(v);}
            ans[h].push_back(curr->val);
            
            if(curr->left)  g.push({curr->left,h+1});
            if(curr->right) g.push({curr->right,h+1});
        }
        return ans;
    }
};