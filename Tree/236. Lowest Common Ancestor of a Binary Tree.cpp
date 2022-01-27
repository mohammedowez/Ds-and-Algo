//iterative
class Solution {
public:
    bool found;
    void traverse(TreeNode* root, vector<TreeNode*>& path, TreeNode* p)
    {
        if(root==NULL||found){
            return;
        }
        path.push_back(root);
        
        if(root==p)
        {
            found=true;
            return;
        }
        
        traverse(root->left,path,p);
        
        if(found){
            return;
        }
        traverse(root->right,path,p);
        
        if(found){
            return;
        }
        
        path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        found=false;
        
        
        vector<TreeNode*> path1;
        
        traverse(root,path1,p);
        vector<TreeNode*> path2;
        found=false;
        
        traverse(root,path2,q);
        TreeNode* ans=root;
        
        for(int i=0;i<path1.size()&&i<path2.size();i++)
        {
            if(path1[i]!=path2[i])
            {
                break;
            }
            ans=path1[i];
        }
        return ans;
    }
};
