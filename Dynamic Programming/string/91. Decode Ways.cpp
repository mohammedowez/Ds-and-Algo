Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

class Solution {
public:
    
    int solve(string s,int ind,int n,vector<int> &dp)
    {
        if(ind==s.size())
            return 1;
        
        if(s[ind]=='0')
            return 0;
        
        
        if(ind==s.size()-1)
            return 1;
        
        
        if(dp[ind]>0)
            return dp[ind];
        
        string ans=s.substr(ind,2);
        
        int takeOne=solve(s,ind+1,n,dp);
        
        int takeTwoPos=0;
        
        if(stoll(ans)<=26 and stoll(ans)>0)
            takeTwoPos=solve(s,ind+2,n,dp);
        
        return dp[ind]=takeOne+takeTwoPos;
        
        
    }
    
    int numDecodings(string s) {
        
        
        if(s[0]=='0' and s.size()==0)
            return 0;
        
        vector<int> res(s.size()+1,0);
    
        return solve(s,0,s.size()-1,res);
       
        
    }
};
