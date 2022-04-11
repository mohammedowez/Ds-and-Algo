Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
  
  class Solution {
public:
    static bool cmp(const pair<int,string> &a,const pair<int,string> &b)
    {
        if(a.first>b.first)
            return true;
        else if(a.first==b.first)
        {
            return a.second<b.second;
        } 
        else 
        {
            return false;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int> mp;
        
        for(auto i:words)
            mp[i]++;
        
        vector<pair<int,string>> pq;
        
        
        
        
        for(auto i:mp)
        {
            pq.push_back({i.second,i.first});
           
        }  
        
        sort(pq.begin(),pq.end(),cmp);
        vector<string> vs;
        
        int i=0;
        while(k--)
        {
            vs.push_back(pq[i].second);
            i++;
            
        }
        
        return vs;
        
    }
};
