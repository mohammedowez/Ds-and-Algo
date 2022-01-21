// Recursion->dfs
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=minDepth(root->left);
        int rh=minDepth(root->right);
        if(lh==0) return 1+rh; //lh=0 means there is no left subtree,so we cannot compare its height to right subtree
        else if(rh==0) return 1+lh; //rh=0 means there is no right subtree
        else return 1+ min(lh,rh);
    }
};


// bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int cnt=1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode *curr=q.front();
                    q.pop();
             
                if(curr->left==NULL && curr->right==NULL)
                    return cnt;
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
            } 
            
            
                cnt++;
        } 
        return cnt;
        
    }
};
