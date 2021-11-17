Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
  
  
  
  
  class Solution{
  public:
  
  int MAH(vector<int> heights,int n)
  
  {  //Maximum Histogram function
  
  vector<int> nsl(n,0);
        stack <pair<int,int> > s1;
        
        for(int i=0;i<n;i++)
        {
            
            while(!s1.empty() and (heights[i]<=s1.top().first))
                s1.pop(); 
            
            
            nsl[i]=(s1.empty())? -1:s1.top().second;
             
            
            s1.push({heights[i],i});
        }
        
        vector<int> nsr(n,0);
        stack<pair<int,int>> s2;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && heights[i]<=s2.top().first)
                s2.pop();
            
            if(s2.empty())
                nsr[i]=n;
            else 
                nsr[i]=s2.top().second;
            
            s2.push({heights[i],i});
            
        }
        
        vector<int> w(n,0);
        for(int i=0;i<n;i++)
        {
            w[i]=nsr[i]-nsl[i]-1;
        } 
        
        int ma=0;
        for(int i=0;i<n;i++)
        {
            ma=max(ma,heights[i]*w[i]);
        } 
        
        
        return ma;
  }
    
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        int max_area=0;
        vector<int> arr;
        for(int j=0;j<m;j++){
            arr.push_back(M[0][j]);
        }
        max_area=max(max_area,MAH(arr,m));
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0) arr[j]=0;
                else arr[j]+=1;
            }
            max_area=max(max_area,MAH(arr,m));
        }
        return max_area; 
        // Your code here
    }
};
