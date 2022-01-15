class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& interval)
    {
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        vector<vector<int>> ans;
        if(interval.size()==0)
            return ans;
        
        sort(interval.begin(),interval.end());
        
        // pushing whole array of index zero([1,3])
        ans.push_back(interval[0]);
        int j=0;
        for(int i=1;i<interval.size();i++)
        {
            
            if(ans[j][1]>=interval[i][0])
                ans[j][1]=max(ans[j][1],interval[i][1]);
            else
            {
                j++;
                ans.push_back({interval[i][0],interval[i][1]});
            }
        }
        return ans;
    }
};
