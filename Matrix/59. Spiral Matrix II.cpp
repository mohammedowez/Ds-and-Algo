Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int> > v(n,vector<int>(n));
        
        int left=0;
        int right=n-1;
        
        int top=0,bottom=n-1;
        int d=0;
        int c=1;
        while(top<=bottom && left<=right)
        {
            
            if(d==0)
            {
                for(int i=left;i<=right;i++)
                    v[top][i]=c++;
                top++;
            } 
            
            else if(d==1)
            {
                
                for(int i=top;i<=bottom;i++)
                    v[i][right]=c++;
                
                right--;
            } 
            
            else if(d==2)
            {
                for(int i=right;i>=left;i--)
                    v[bottom][i]=c++;
                
                bottom--;
            } 
            
            else if(d==3)
            {
                for(int i=bottom ;i>=top;i--)
                    v[i][left]=c++;
                
                left++;
            }
            d=(d+1)%4;
        }
        
       /* vector<vector<int> > res;
        for(int i=0;i<n;i++)
        {
            vector<int> v1;
            for(int j=0;j<n;j++)
                v1.push_back(v[i][j]);
            res.push_back(v1);
        }
        */
        
        return v;
    }
};
