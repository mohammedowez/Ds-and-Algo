Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]


class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        
        // time complexity is O(nklongk) ->O(nlogn)
        // space complexity is o(n)
        
        vector<vector<string>> v;
        
        if(strs.size()==0)
            return v;
        
        unordered_map<string,vector<string>> mps;
        
        string temp;
        for(int i=0;i<strs.size();i++)
        {
            temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            
            mps[strs[i]].push_back(temp);
        } 
        
        for(auto i:mps)
        {
            v.push_back(i.second);
        }
        
        return v;
        
        
    }
};
