Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

  // Case 1:-
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:-
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:-
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//     --------------

class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>&v) 
    {
        sort(v.begin(),v.end());
        int count=0,l=0,r=1,n=v.size();
        while(r<n)
        {
            if(v[l][1]<=v[r][0]) // Non-overlapping case(Case 1)
            {
                l=r;
                r++;
            }
            else if(v[l][1]<=v[r][1])  // Case 2
            {
                count++;
                r++;
            }
            else if(v[l][1]>v[r][1])   // Case 3
            {
                count++;
                l=r;
                r++;
            }
        }
        return count;
    }
};
  class Solution {
public:
    
    static bool comp(vector<int> &a ,vector<int> &b)
    {
         
            return a[1]<b[1];
        
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& in)
    {
        
        if(in.size()==1)
            return 0;
        
        sort(in.begin(),in.end(),comp);
    
        for(auto i:in)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
        
         int end = in[0][1];
        int count = 1;
        for (int i = 1; i < in.size(); i++) {
            if (in[i][0] >= end) 
            {
                end = max(end,in[i][1]);
                count++;
            }
        }
        return in.size() - count;
        
        
    }
};
