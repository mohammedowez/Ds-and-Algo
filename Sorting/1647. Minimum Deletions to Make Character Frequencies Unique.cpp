Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
  
  class Solution {
public:
    int minDeletions(string s) {
     
        vector<int> v(26,0);
        for(char i:s)
            v[i-'a']++;
        
        unordered_map<int,int> mp;
        
        int ans=0;
        
        for(int i=0;i<26;i++)
        {
            int c=v[i];
            if(c==0)
                continue;
            if(mp.find(c)!=mp.end())
            {
               // cout<<i<<"="<<v[i]<<" ";
                ans++;
                v[i]--;
                i--;
            }
            else
                mp[c]=1;  
        }
        return ans;
        
    }
};
