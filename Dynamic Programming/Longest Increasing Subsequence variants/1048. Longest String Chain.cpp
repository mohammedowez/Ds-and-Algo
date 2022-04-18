Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
  
  class Solution {
public:
    
    // to sort according to the size
    static bool cmp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    
    // this is to comapre the string and see where its is added one and has increasing order 
    bool compare(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1)
            return 0;
        
        int first=0;
        int second=0;
        while(first<s1.size())
        {
            if(s1[first]==s2[second])
            {
                first++;
                second++;
            } 
            else
                first++;
        } 
        
        if(first==s1.size() and second==s2.size())
            return 1;
        return 0;
    }
    
    int longestStrChain(vector<string>& words) {
        
        
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int> dp(n,1);
        
        int maxi=1;
        // use longest increasing code and change it just a function in it
        for(int i=0;i<n;i++)
        {
            for(int pre=0;pre<i;pre++)
            {
                if(compare(words[i],words[pre]) and 1+dp[pre]>dp[i])
                {
                    dp[i]=1+dp[pre];
                }
            } 
            if(dp[i]>maxi)
                maxi=dp[i];
        } 
        
        return maxi;
    }
};
