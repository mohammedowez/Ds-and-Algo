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
    
    TreeNode *solve(vector<int>& inorder, vector<int>& postorder,int start,int end,int &pos)
    {
        if(start>end)
            return NULL;
        
        TreeNode *curr=new TreeNode(postorder[pos]);
        pos--;
        
        int mid;
        for(int i=start;i<end;i++)
        {
            if(inorder[i]==curr->val)
            {
                mid=i;
                break;
            }
        } 
        
        curr->right=solve( inorder,postorder, mid+1,end,pos);
        curr->left=solve( inorder,postorder, start,mid-1,pos);
         
        
        return curr;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int postIndex=postorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1,postIndex);
    }
};
