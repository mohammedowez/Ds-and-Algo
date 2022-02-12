class Solution {
public:
    
    int ans=0;
    void solve(TreeNode *root,int maxi,int mini)
    {
        if(root==NULL)
            return;
        
        
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        
        ans=max(ans,abs(mini-maxi));
        solve(root->left,maxi,mini);
        solve(root->right,maxi,mini);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        solve(root,maxi,mini);
        
        return ans;
    }
};
