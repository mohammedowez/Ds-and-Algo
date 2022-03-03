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

// Diameter of tree it is an alternative solution for this problem just add the things.

// parent node is equal to the root node then it will return max(left,right)+1

class Solution {
public:
    int ans=0;
    
    int solve(TreeNode *root,int parent)
    {
        if(root==NULL)
            return 0;
        
        int left=solve(root->left,root->val);
        int right=solve(root->right,root->val);
        
        ans=max(left+right,ans);
        
        //if parent exists (node is not root)
	//if the current value matches with the parent value then we return the maxLength betn left and right + 1(current element).
        if(parent==root->val)
        {
            return max(left,right)+1;
        } 
        
        return 0;
        
    }
    
    
    int longestUnivaluePath(TreeNode* root) {
        
        solve(root,0);
        
        return ans;
    }
};
