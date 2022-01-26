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
    int ans=0;
    void solve(TreeNode *root,int s)
    {
        if(root==NULL)
            return;
        
        if(root->val==s)
        {
            ans++;
        } 
        //cout<<"s1 "<<s<<"\n";
        solve(root->left,s-root->val);

        solve(root->right,s-root->val);
        //cout<<"s2 "<<s<<"\n";
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return 0;
        
        solve(root,targetSum);
        
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};
