Example 1:

Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:

Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> v;
        map<int,int> mp;
        for(int i=0;i<intervals.size();i++)
            mp[intervals[i][0]]=i;
        
        
        for(int i=0;i<intervals.size();i++)
        {
            auto f=mp.lower_bound(intervals[i][1]);
            if(f!=mp.end())
                v.push_back(f->second);
            else 
                v.push_back(-1);
                 
        } 
        
        return v;
        
    }
};
