Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<bool> vis(n,0);
        
        queue<int> qt;
        qt.push(0);
        
        
        
        while(!qt.empty())
        {
            int node=qt.front();
             vis[node]=1;
            qt.pop();
            
            for(auto i: rooms[node])
            {
                if(vis[i]==0)
                {
                   
                    qt.push(i);
                }
            }
            
        } 
        
        for(auto i: vis)
        {
            if(i==0)
                return 0;
         } 
        
        return 1;
    }
    
    
};
