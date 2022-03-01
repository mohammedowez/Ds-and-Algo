class Solution 
{
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    void solve(Node *curr,vector<int> &v)
    {
        if(curr==NULL)
            return;
        
        v.push_back(curr->data);
        solve(curr->left,v);
        solve(curr->right,v);
        
    }
    
    int dupSub(Node *root) 
    {
         // code here
         queue<Node *> q;
         q.push(root);
         
         map< vector<int>, int> mp;
         
         while(!q.empty())
         {
             Node *curr=q.front();
                q.pop();
            
            vector<int> v;  
            solve(curr,v);
            
            if(v.size()>=2)
            {
                mp[v]++;
                if(mp[v]==2)
                {
                    return 1;
                }
            }
             
             
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
         }  
         
          
          return 0;
         
    }
};
