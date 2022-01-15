Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

  
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
