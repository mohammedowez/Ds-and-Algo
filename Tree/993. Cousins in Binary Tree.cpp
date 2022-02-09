class Solution {
public:
    int xh,yh,xp,yp;
    
    void solve(TreeNode *root,int x,int y,int h,int p)
    {
        if(!root)
            return ;
        
        if(root->val==x)
        {
            xp=p;
            xh=h;
            return ;
        }
        
        if(root->val==y)
        {
            yp=p;
            yh=h;
            return ;
        } 
        
        solve(root->left,x,y,h+1,root->val);
        
        solve(root->right,x,y,h+1,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        
         if(root->val==x || root->val==y) 
             return false;
        
        
        
        solve(root,x,y,0,0);
        
        if(xp!=yp and xh==yh)
            return 1;
        return 0;
    }
};
