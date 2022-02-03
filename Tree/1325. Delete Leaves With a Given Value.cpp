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
class Solution 
{
    
public:
    
   TreeNode* removeLeafNodes(TreeNode* root, int target) 
   {
        postorder(root,target);
        return root;
    }

    void postorder(TreeNode* &root,int target)
    {
        if(!root)
            return;
        
        postorder(root->left,target);
        postorder(root->right,target);
        
        if(root->val==target && root->left==NULL && root->right==NULL)
        {
            root=NULL;
        }
    }
};
