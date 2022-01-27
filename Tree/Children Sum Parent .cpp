 bool solve(Node *root)
    {
        
        if(root==NULL or (root->left==NULL && root->right==NULL))
            return 1;
            
        
        
            int s=0;
        
        if(root->left)
            s+=root->left->data;
            
        if(root->right)
            s+=root->right->data;
        
        
        if(s==root->data && solve(root->left) && solve(root->right))
        {
            return 1;
        } 
        else
            return 0;
            
        
        
    }
    
    int isSumProperty(Node *root)
    {
     // Add your code here
     
     
    
    if(solve(root))
        return 1;
    
    return 0;
        
    }
