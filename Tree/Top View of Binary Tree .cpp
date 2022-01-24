


       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7







class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL)
            return {};
            
            
        
        queue<pair<Node*,int>> q;
            q.push({root,0});
        
        map<int,int> mp;
        
        vector<int> res;
        
        while(!q.empty())
        {
            Node *key=q.front().first;
            int value=q.front().second;
                q.pop();
            
            if(mp.find(value) == mp.end()) 
                    mp[value]=key->data;
            
            if(key->left)
                q.push({key->left,value-1});
                
            
            if(key->right)
                q.push({key->right,value+1});
        
        } 
        
        for(auto i:mp)
        {
            res.push_back(i.second);
        }
         
         
         return res;
        
        
    }
