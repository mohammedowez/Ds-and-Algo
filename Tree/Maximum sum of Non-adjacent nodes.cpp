class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    // instead of calling it u have to return the function
    unordered_map<Node*,int> mp;
    
    int getMaxSum(Node *root) 
    {
        
      //  ios_base::sync_with_stdio(0),cin.tie(0);
        
        // Add your code here
        
        if(root==NULL)
            return 0;
        
        
        if(mp[root])
            return mp[root];
        
        //  taking there grand childerns     
        int withparent=root->data;
        
        
        
        if(root->left)
        {
            withparent+=getMaxSum(root->left->left);
            withparent+=getMaxSum(root->left->right);
        } 
        
        if(root->right)
        {
            withparent+=getMaxSum(root->right->left);
            withparent+=getMaxSum(root->right->right);
        } 
        
        // taking only childerns
        int withOutParent=getMaxSum(root->left)+getMaxSum(root->right);
        
        
        return mp[root]=max(withOutParent,withparent);
    }
};
