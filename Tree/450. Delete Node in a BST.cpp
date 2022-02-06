class Solution {
public: 
    
    int findMax(TreeNode *root)
    {
        int ma=INT_MIN;
        while(root)
        {
            ma=max(ma,root->val);;
            root=root->right;
        } 
        
        return ma;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL; 
        
        if(root->val<key)
            deleteNode(root->right,key);
        
        else if(root->val>key)
            deleteNode(root->left,key);
         
        else 
        {
            if(root->left and root->right)
            { 
                int v=findMax(root->left);
                root->val=v;
               
                root->left=deleteNode(root->left,key);
                
                return root;
            } 
        
            else if(root->left!=NULL)
            {
               return root->left;
            } 
            else if(root->right!=NULL)
            {
                
               return root->right;
            } 
            else 
                return NULL;
        } 
        
        return root;
        
        
    }
};
