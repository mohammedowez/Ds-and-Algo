Input:
N = 6
arr[] = {3,0,0,2,0,4}

Output:
10

  
  Explanation: 
Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
  In this case, 6 units of rain water (blue section) are being trapped.



class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        
        int n=height.size();
        
        vector<int> v(n);
        vector<int> msl(n);
        vector<int> mrl(n);
        
        
        msl[0]=height[0];
        for(int i=1;i<n;i++)
        {
            msl[i]=max(msl[i-1],height[i]);
        } 
        
        mrl[n-1]=height[n-1]; 
        for(int i=n-2;i>=0;i--)
        {
           mrl[i]=max(mrl[i+1],height[i]);
            
        } 
        
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=(min(mrl[i],msl[i]))-height[i];
        }  
        
       
        return s;
        
    }
};
