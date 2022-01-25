class Solution {
public:
   vector <int> boundary(Node *root)
    {
        vector<int> v;
        if(root==NULL)
            return v;
        v.push_back(root->data);
        left_node(root->left,v);
        leaf_node(root,v);
        right_node(root->right,v);
        return v;
    }
    void left_node(Node* root,vector<int> &v)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return;
            
        v.push_back(root->data);
        if(root->left)
            left_node(root->left,v);
        else if(root->right)
            left_node(root->right,v);
    }
    void leaf_node(Node* root,vector<int> &v)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->data);
            return;
        }
        leaf_node(root->left,v);
        leaf_node(root->right,v);
    }
    void right_node(Node* root,vector<int> &v)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return;
       
        
        if(root->right)
            right_node(root->right,v);
        else if(root->left)
            right_node(root->left,v);
        
         v.push_back(root->data);
        
    }
