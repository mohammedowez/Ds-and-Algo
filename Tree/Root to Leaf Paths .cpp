void solve(Node *root,vector<int> v,vector<vector<int>> &ans)
 {
     v.push_back(root->data);
     
     if(root==NULL)
        return;
        
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(v);
            return;
        } 
        
        if(root->left)
            solve(root->left,v,ans);
        if(root->right)
            solve(root->right,v,ans);
        
 }
 
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>>  ans;
    // Code here
    if(root==NULL)
        return ans;
    vector<int> v;
    
    solve(root,v,ans);
    
    return ans;
    
}
