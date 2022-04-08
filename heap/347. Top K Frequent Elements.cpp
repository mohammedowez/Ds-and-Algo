Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

// first solution

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> v;
        
        priority_queue<pair<int,int> > pq;
        
        map<int,int> mp;
        
        for(auto i:nums)
            mp[i]++;
        
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        } 
        
       /* while(!pq.empty())
        {
            cout<<pq.top().second<<" ";
            pq.pop();
            
        }*/
        for(int i=0;i<k;i++)
        {
            v.push_back(pq.top().second);
            pq.pop();
        } 
        
        return v;
        
        
    }
};


