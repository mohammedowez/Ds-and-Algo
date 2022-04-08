Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


class Solution {
public:
    // create a max heap in the form of pair and try to add the x- arr in to the heap  
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        
        
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
        } 
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        } 
        
        sort(res.begin(),res.end());
        return res;
        
        
        
    }
};
