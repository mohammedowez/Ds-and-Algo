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
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            TreeNode *q1=q.front();
                q.pop();
            TreeNode *q2=q.front();
                q.pop();
            
            if(q1==NULL and q2==NULL)
                continue;
            
            else if(q1==NULL or q2==NULL)
                return 0;
            
            else if(q1->val!=q2->val)
                return 0;
            
            q.push(q1->left);
            q.push(q2->right);
            
            
            q.push(q1->right);
            q.push(q2->left);
        } 
        
        return 1;
        
        
        
    }
};
