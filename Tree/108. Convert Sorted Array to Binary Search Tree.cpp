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
    
    TreeNode *solve(vector<int> &nums,int l,int h)
    {
        if(l>=h)
            return NULL;
        
        int m=(h+l)>>1;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = solve(nums, l, m);
        node->right = solve(nums, m+1, h);
            
        return node;
            
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int l=0;
        int e=nums.size();
        
        return solve(nums,l,e);
        
        
    }
};
