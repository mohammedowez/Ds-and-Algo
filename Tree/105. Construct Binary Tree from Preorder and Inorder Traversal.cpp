/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pos=0;
    TreeNode *solve(map<int,int> &mp,vector<int>& inorder, vector<int>& preorder,int start,int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode *curr=new TreeNode(preorder[pos++]);
        
       int mid=mp[curr->val];
    
        
        curr->left=solve(mp, inorder,preorder, start,mid-1);
        curr->right=solve(mp, inorder,preorder, mid+1,end); 
        
        return curr;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        return solve(mp,inorder,preorder,0,inorder.size()-1);
    }
}; 



class Solution {
public:
    int pos=0;
    TreeNode *solve(vector<int>& inorder, vector<int>& preorder,int start,int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode *curr=new TreeNode(preorder[pos++]);
        
        int mid;
        for(int i=start;i<end;i++)
        {
            if(inorder[i]==curr->val)
            {
                mid=i;
                break;
            }
        } 
        
        curr->left=solve( inorder,preorder, start,mid-1);
        curr->right=solve( inorder,preorder, mid+1,end); 
        
        return curr;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return solve(inorder,preorder,0,inorder.size()-1);
    }
};
