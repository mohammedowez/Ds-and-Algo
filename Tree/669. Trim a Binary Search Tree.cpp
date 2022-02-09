class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root==nullptr)
            return nullptr;
        
        // if the value is outside the less the low then go for right
        if(root->val<low)
           return trimBST(root->right,low,high);
        
        
        // if the value is outside the less the low then go for left 
        if(root->val >high)
            return trimBST(root->left,low,high);
        
        
        // if u want to connect the other nodes then use this 
        root->left=trimBST(root->left,low,high);
         root->right=trimBST(root->right,low,high);
        
        // return the root 
        return root;
        
        
    }
};
