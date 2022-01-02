Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

  
  class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        
        int l=0;
        int h=a.size()-1;
        if(target<=a[0])
            return 0;
        
        if(target>a[h])
            return h+1;
        
        int res=1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(a[m]==target)
            {
                return m;
            }
            else if(a[m]<target)
                l=m+1;
            else
                h=m-1;
        } 
        
        return l;
        
        
    }
};
