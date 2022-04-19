Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
  
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
    TreeNode *pre=NULL,*first=NULL ,*second=NULL;
    
    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;
        
        solve(root->left);
         
            if(pre!=NULL && root->val<pre->val)
            {
                if(first==NULL)
                    first=pre;
                second=root;
            } 
            pre=root;
        
        
        solve(root->right);
        
            
    }
    
    void recoverTree(TreeNode* root) {
        
        solve(root);
        
        swap(first->val,second->val);
        
    }
};
