Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        unordered_map<int,int> mp;
        int i=0,j=0;
        vector<int> v;
        while(i<n)
        {
            mp[a[i]]++;
            if(i-j+1<k)
            {
                i++;
            } 
            else if(i-j+1==k)
            {
                int m=mp.size();
                v.push_back(m);
                mp[a[j]]--;
                if(mp[a[j]]==0)
                    mp.erase(a[j]);
                j++;
                i++;
            } 
            
        } 
        
        return v;
        
    }
};
