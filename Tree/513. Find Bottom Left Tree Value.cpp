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
    
    void solve(vector<int> &v,int l,TreeNode *root)
    {
        if(root==NULL)
            return ;
        
        if(l==v.size())
        {
            v.push_back(root->val);
        } 
        
        solve(v,l+1,root->left);
        solve(v,l+1,root->right);
        

    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        
        vector<int> v;
        solve(v,0,root);
        
        int size=v.size();
        return v[size-1];
        
        
        
    }
};
