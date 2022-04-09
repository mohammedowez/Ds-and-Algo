Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
typedef pair<int,pair<int,int>> pp; 
class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        
        vector<vector<int>> res;
        
        // create a max heap
        priority_queue<pp> pq;
        
        
        // push the elements in the max_heap
        for(int i=0;i<points.size();i++)
        {
            int x=abs(points[i][0]);
            int y=abs(points[i][1]);
            
            pq.push({x*x+y*y,{points[i][0],points[i][1]}});
            
            if(pq.size()>k)
                pq.pop();
            
        } 
        
        while(k--)
        {
            pair<int,int> p=pq.top().second;
            
        
            res.push_back({p.first,p.second});
            pq.pop();
            
        } 
        
        return res;
        
        
    }
};  
    
