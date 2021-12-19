Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.




class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> mp;
        int c=0;
        int s=0;
        
        for(int i=0;i<n;i++)
        {
           
            if(mp.count(k-arr[i]))
            {
                c=c+mp[k-arr[i]];
            } 
            mp[arr[i]]++;
        } 
        
        return c;
    }
};
