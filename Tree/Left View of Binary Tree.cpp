void solve(vector<int> &v,int level,Node *root)
{
    if(root==NULL)
        return;
        
    if(level==v.size())
        v.push_back(root->data);
        
    solve(v,level+1,root->left);
    solve(v,level+1,root->right);
    
    
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   if(root==nullptr)
    return {};
   
   vector<int> v;
   solve(v,0,root);
   
   return v;
   
   
   
}
