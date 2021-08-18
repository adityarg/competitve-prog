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
// Memory efficient
// Can try again
class Solution {
public:
    TreeNode* traverse(vector<int>& pre, int i1,int j1 ,vector<int>& in, int i2,int j2)
    {
        if(i2>j2) return NULL;
        
        TreeNode* root=new TreeNode(pre[i1]);
        
        int q;
        for(int i=i2;i<=j2;i++) if(in[i]==pre[i1]) {q=i; break;}
        
        root->left  = traverse(pre,i1+1,i1+q-i2,in,i2,q-1);
        root->right = traverse(pre,j1+1+q-j2,j1,in,q+1,j2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return traverse(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};


// class Solution {
// public:
//     vector<int> slice(vector<int>& preorder, int x,int y)
//     {
//         vector<int> v;
//         for(int i=x;i<=y;i++) v.push_back(preorder[i]);
//         return v;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//     {
//         int n=inorder.size();
//         if(n==0) return NULL;
        
//         TreeNode* root=new TreeNode(preorder[0]);
        
//         int q;
//         for(int i=0;i<n;i++) if(inorder[i]==preorder[0]) {q=i; break;}
        
//         auto l1=slice(preorder,1,q),l2=slice(inorder,0,q-1);
//         auto r1=slice(preorder,q+1,n-1), r2=slice(inorder,q+1,n-1);
//         root->left  = buildTree(l1,l2);
//         root->right = buildTree(r1,r2);
//         return root;
//     }
// };