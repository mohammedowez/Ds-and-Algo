Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

  
  class Solution {
public:
    
    
    static bool solve(string &wor,string &pat)
    {
        
        int j=0;
        int i=0;
        while(i<pat.size() &&j<wor.size())
        {
            if(wor[j]==pat[i])
                i++,j++;
            else 
                i++;
        }
        return (j==wor.size());
        
        
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        int cnt=0;
        unordered_map<string,int> mp;
        for(auto i:words)
            mp[i]++;
        
        
        for(auto word :mp)
        {
            string a=word.first;
            if(solve(a,s))
                cnt=cnt+word.second;
        }
        
        return cnt;
        
    }
};
