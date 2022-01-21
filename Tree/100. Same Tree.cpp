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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //for iterative approach, we generally follow the 4 major steps:
		//1. Make a queue 
		//2. Push the current Node in the queue (starting from the root node)
		//3. Process the queue, while its not empty (by adding its left & right child)
		//4. Once the queue is empty, then alorithm has finished

        
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        
        while(!que.empty())
        {
           TreeNode *q1=que.front();
                que.pop();
            
            TreeNode *q2=que.front();
                que.pop();
            
            //meet the question conditions
            if(q1==NULL and q2==NULL)
                continue;
            
            if(q1==nullptr or q2==NULL)
                return 0;
            
            if(q1->val!=q2->val)
                return 0;
            
            que.push(q1->left);
            que.push(q2->left);
            que.push(q1->right);
            que.push(q2->right);
            
        } 
        
        return 1;
        
    }
};
