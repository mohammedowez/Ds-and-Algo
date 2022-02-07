vector<int> diagonal(Node *root)
{
   // your code here
   
   
   vector<int> v;
   
   queue<Node*> qt;
   qt.push(root);
   
   while(!qt.empty())
   {
       Node *curr=qt.front();
       qt.pop();
       
       while(curr)
       {
           if(curr->left)
            qt.push(curr->left);
            
            v.push_back(curr->data);
            
            curr=curr->right;
       }
   } 
   
   return v;
   
}
