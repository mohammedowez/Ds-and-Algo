class Solution {
public:
    int palindrom = 0;  // number of psuedo palindrom path 
    void solve(TreeNode* root , vector<int>& frequency_cnt)
    {
        if(!root)
            return ;
        frequency_cnt[root->val]++;
        if(!root->left and !root->right)
        { // if current root is leaf
            int cnt =0;
            for(int i=1;i<=9;i++){
                if(frequency_cnt[i]%2==1 )
                { // cheking for odd frequency node
                    cnt++;
                }
            }
            if(cnt<=1)// there r less than or queal to 1 val having odd frequency then the given path will be palindrome
                palindrom++;
        }
        solve(root->left , frequency_cnt);
        solve(root->right,frequency_cnt);
        frequency_cnt[root->val]--;  // backtracking
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> frequency_cnt(10,0); // fro counting the frequncy of a root to leaf path
        solve(root,frequency_cnt);
        return palindrom;
    }
};
