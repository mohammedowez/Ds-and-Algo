int ma=0;
    bool solve(Node *root,int i)
    {
        if(root==NULL)
            return 1;
        if(root->left==NULL and root->right==NULL)
        {
            if(ma==0)
            {
                ma=i;
                return 1; 
            } 
            else 
            {
                if(ma==i)
                return 1;
                else 
                return 0;
            }
        } 
        
        bool a=solve(root->left,i+1);
        bool b=solve(root->right,i+1);
        
        return a&&b;
    }
    
    bool check(Node *root)
    {
        //Your code here
        
        if(solve(root,0))
            return 1;
        return 0;
    }
