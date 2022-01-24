

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(root==NULL)
            return {};
            
        
         vector<int> v;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
       
        
        map<int,int> mp;
        
        while(!q.empty())
        {
            Node* key=q.front().first;
            int value=q.front().second;
            q.pop();
            mp[value]=key->data;
            if(key->left)
                q.push({key->left,value-1});
            
            if(key->right)
                q.push({key->right,value+1});
        } 
        
        for(auto i:mp)
        {
            v.push_back(i.second);
        }
        
        return v;
        
        
        
        
    }
};
