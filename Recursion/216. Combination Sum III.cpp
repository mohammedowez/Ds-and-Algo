Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(int k,int n,int id)
    {
        if(k<0 or n<0)
            return;
        if(k==0 and n==0)
        {
            ans.push_back(v);
            return;
        } 
        
        for(int i=id;i<=9;i++)
        {
            v.push_back(i);
            
            solve(k-1,n-i,i+1);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        ans.clear();
        solve(k,n,1);
        
        return ans;
    }
};
