Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, 
                               vector<int>& newInterval) 
    {
        
        vector<vector<int> > v;
        
        int s=newInterval[0];
        int e=newInterval[1];
        
        int n=intervals.size();
        
        
        // starting points before the intervals
        int i=0;
        while(i<n && intervals[i][1]<s)
            v.push_back(intervals[i++]);
        
        
        // middle of the intervals 
        while(i<n && intervals[i][0]<=e)
        {
            s=min(intervals[i][0],s);
            e=max(intervals[i][1],e);
            i++;
        } 
        v.push_back({s,e});
        
        // Remaining Intervals
        while(i<n)
            v.push_back(intervals[i++]);
        
        
        return v;
        
        
    }
};
