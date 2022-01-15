Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].


class Solution 
{
public:
    // Soring in ascending order
    static bool cmp(vector<int> &p1,vector<int> &p2)
    {
        return p1[0]<p2[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) 
    {    
        // Time complexity is O(nlogn);
        // sp =o(1);
        
        // Time Complexity if sorting is -O(nlogn)
        sort(points.begin(),points.end(),cmp);
        
        // sort(points.begin(),points.end());
        for(auto &i:points)
        {
            for(auto &j:i)
                    cout<<j<<" ";
            cout<<endl;
        }
        // Taking the first point of 2D array index of 1st Poistion   
        int high=points[0][1];
        int cnt=1;
        
        // Loop Time Complexity id -O(n)
        for(int i=1;i<points.size();i++)
        {
            if(high>=points[i][0])
                high=min(high,points[i][1]);
            else 
            {
                cnt++;
                high=points[i][1];
            }
        } 
        
        return cnt;
    }
};
