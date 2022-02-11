class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,long long>> qu;
            qu.push({root,1});
        
        unsigned int ans=0;
        
        while(!qu.empty())
        {
            unsigned int l,r;
            l=qu.front().second;
            r=l;
            int s=qu.size();
            while(s--)
            {
                TreeNode* temp=qu.front().first;
                r=qu.front().second;
                    qu.pop();
                
                if(temp->left)
                        qu.push({temp->left,r*2});
                if(temp->right)
                        qu.push({temp->right,r*2+1});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
